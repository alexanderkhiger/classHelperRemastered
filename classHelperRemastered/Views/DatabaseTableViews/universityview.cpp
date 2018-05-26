#include "universityview.h"

UniversityView::UniversityView(QueryService *service) {
    this->service = service;
    model = new UniversityModel(service);
    tableModel = 0;
    isSubMenuActive = false;
    createUI();
    receiveModel();
    resizeTable();
    tableView->viewport()->installEventFilter(this);
    createConnections();
}

bool UniversityView::eventFilter(QObject *obj, QEvent *event) {

    if (event->type() == QEvent::MouseButtonDblClick) {
        QMouseEvent * mouseEvent = static_cast <QMouseEvent *> (event);
        if (mouseEvent -> button() == Qt::LeftButton) {
            changeControlsState();
        }
    }
    return QWidget::eventFilter(obj, event);
}

void UniversityView::createUI() {
    workfield = new QGroupBox;
    alwaysShownSubMenu = new QGroupBox;
    togglableSubMenu = new QGroupBox;

    nameField = new QLineEdit;
    nameField->setPlaceholderText(tr("Название"));
    nameField->setToolTip(tr("Название университета"));

    shortNameField = new QLineEdit;
    shortNameField->setPlaceholderText(tr("Аббревиатура"));
    shortNameField->setToolTip(tr("Аббревиатура университета"));

    addButton = new QPushButton(tr("Добавить"));

    deleteButton = new QPushButton(tr("Удалить"));
    deleteButton->setEnabled(0);

    confirmAdditionButton = new QPushButton(tr("OK"));

    confirmChoiceButton = new QPushButton(tr("Выбрать университет"));
    confirmChoiceButton->setEnabled(0);

    exitButton = new QPushButton(tr("Выход"));

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(exitButton, QDialogButtonBox::RejectRole);
    buttonBox->addButton(confirmChoiceButton, QDialogButtonBox::AcceptRole);

    tableView = new CustomTableView;
    tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tableView->verticalHeader()->setVisible(0);

    togglableSubMenuLayout = new QHBoxLayout;
    togglableSubMenuLayout->addWidget(nameField);
    togglableSubMenuLayout->addWidget(shortNameField);
    togglableSubMenuLayout->addWidget(confirmAdditionButton);
    togglableSubMenu->setLayout(togglableSubMenuLayout);
    togglableSubMenu->setVisible(0);
    isSubMenuActive = false;

    alwaysShownSubMenuLayout = new QHBoxLayout;
    alwaysShownSubMenuLayout->addWidget(addButton);
    alwaysShownSubMenuLayout->addWidget(deleteButton);
    alwaysShownSubMenu->setLayout(alwaysShownSubMenuLayout);

    workfieldLayout = new QVBoxLayout;

    workfieldLayout->addWidget(tableView);
    workfieldLayout->addWidget(togglableSubMenu);
    workfieldLayout->addWidget(alwaysShownSubMenu);

    workfield->setLayout(workfieldLayout);

    viewLayout = new QVBoxLayout;
    viewLayout->addWidget(workfield);
    viewLayout->addWidget(buttonBox);

    areControlsActive = true;

    setLayout(viewLayout);
    setMinimumSize(300,300);
    setWindowTitle(tr("Выбор университета"));
}

void UniversityView::changeSubMenuState() {
    nameField->clear();
    shortNameField->clear();
    if (isSubMenuActive == false) {
        togglableSubMenu->setVisible(1);
        isSubMenuActive = true;
        addButton->setStyleSheet("background-color:gray; border-color:black; color:white");
    }
    else {
        togglableSubMenu->setVisible(0);
        isSubMenuActive = false;
        addButton->setStyleSheet("");
    }
}

void UniversityView::changeControlsState() {
    areControlsActive = !areControlsActive;
    isSubMenuActive = areControlsActive;
    confirmChoiceButton->setVisible(areControlsActive);
    alwaysShownSubMenu->setVisible(areControlsActive);
    togglableSubMenu->setVisible(areControlsActive);
}

void UniversityView::resizeTable() {
    QHeaderView *hHeader = tableView->horizontalHeader();
    setMinimumSize(120,300);
    resize(120,300);
    int neededWidth = 0;

    tableView->resizeColumnsToContents();
    tableView->resizeRowsToContents();

    for (int c = 0; c < tableView->horizontalHeader()->count(); c++) {
        neededWidth += hHeader->sectionSize(c) + 20;
    }

    setMinimumSize(neededWidth,300);

    tableView->horizontalHeader()->setStretchLastSection(true);
}

void UniversityView::receiveModel() {
    connect(model,SIGNAL(tableModelReceived(QSqlTableModel*)),this,SLOT(setModel(QSqlTableModel*)));
    model->receiveModel("universitet");
}

void UniversityView::setModel(QSqlTableModel *model) {
    tableModel = model;
    tableModel->setHeaderData(0,Qt::Horizontal,tr("ID университета"));
    tableModel->setHeaderData(1,Qt::Horizontal,tr("Название"));
    tableModel->setHeaderData(2,Qt::Horizontal,tr("Аббревиатура"));
    tableView->setModel(tableModel);
}

void UniversityView::recordWasClicked() {
    deleteButton->setEnabled(1);
    confirmChoiceButton->setEnabled(1);
}

void UniversityView::deleteRecord() {
    if (tableModel == 0) {
        QMessageBox::StandardButton errorMsg;
        errorMsg = QMessageBox::information(this,tr("Ошибка"),tr("Модель не загружена. Критическая ошибка"),QMessageBox::Ok);
        return;
    }

    QModelIndex idIndex = tableView->model()->index(tableView->currentIndex().row(),0,QModelIndex());
    QModelIndex nameIndex = tableView->model()->index(tableView->currentIndex().row(),1,QModelIndex());
    QModelIndex shortnameIndex = tableView->model()->index(tableView->currentIndex().row(),2,QModelIndex());

    QString idData = tableView->model()->data(idIndex).toString();
    QString nameData = tableView->model()->data(nameIndex).toString();
    QString shortnameData = tableView->model()->data(shortnameIndex).toString();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Удаление"), QString(tr("Удалить запись %1 | %2 | %3?")).arg(idData).arg(nameData).arg(shortnameData), QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        model->performQuery(tableModel,UniversityModel::deleteRecord,tableView->currentIndex().row());
        deleteButton->setEnabled(0);
        confirmChoiceButton->setEnabled(0);
    }
}

void UniversityView::addRecord() {
    if (nameField->text().isEmpty() || shortNameField->text().isEmpty()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Подтверджение"), QString(tr("Не все поля заполнены. Все равно добавить запись?")), QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::No)
            return;
    }

    if (tableModel == 0) {
        QMessageBox::StandardButton errorMsg;
        errorMsg = QMessageBox::information(this,tr("Ошибка"),tr("Модель не загружена. Критическая ошибка"),QMessageBox::Ok);
        return;
    }

    model->performQuery(tableModel,UniversityModel::insertRecord,tableView->currentIndex().row(),nameField->text(),shortNameField->text());
    nameField->clear();
    shortNameField->clear();
    deleteButton->setEnabled(0);
    confirmChoiceButton->setEnabled(0);
}

void UniversityView::editRecord() {
    if (universityBeforeUpdate == universityAfterUpdate) {
        return;
    }
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Подтверджение"), QString(tr("Изменить: %1 на %2 ?").arg(universityBeforeUpdate).arg(universityAfterUpdate)), QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::No) {
        tableModel->revertAll();
        universityAfterUpdate = universityBeforeUpdate;
        return;
    }
    else {
        if (!tableModel->submitAll()) {
            emit errorHandler(tableModel->lastError());
            tableModel->revertAll();
            universityAfterUpdate = universityBeforeUpdate;
            return;
        }
        resizeTable();
        deleteButton->setEnabled(0);
        confirmChoiceButton->setEnabled(0);
    }
}

void UniversityView::successHandler() {
    QModelIndex idIndex = tableView->model()->index(tableView->currentIndex().row(),0,QModelIndex());
    QModelIndex nameIndex = tableView->model()->index(tableView->currentIndex().row(),1,QModelIndex());
    QModelIndex shortnameIndex = tableView->model()->index(tableView->currentIndex().row(),2,QModelIndex());

    QString idData = tableView->model()->data(idIndex).toString();
    QString nameData = tableView->model()->data(nameIndex).toString();
    QString shortnameData = tableView->model()->data(shortnameIndex).toString();

    MainWindowView *frm = new MainWindowView(service, idData, nameData, shortnameData, this);
    frm->show();
    hide();
}

void UniversityView::errorHandler(QSqlError error) {
    QMessageBox::StandardButton errorMsg;
    errorMsg = QMessageBox::critical(this,tr("Ошибка"),error.text(),QMessageBox::Ok);
}

void UniversityView::changedFrom(const QItemSelection &selected) {
    universityBeforeUpdate = tableView->model()->data(selected.indexes()[0]).toString();
    universityAfterUpdate = tableView->model()->data(selected.indexes()[0]).toString();
}

void UniversityView::changedTo(const QModelIndex &bIndex) {
    universityAfterUpdate = tableView->model()->data(bIndex).toString();
}

void UniversityView::createConnections() {
    connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(confirmChoiceButton, SIGNAL(clicked(bool)), this, SLOT(successHandler()));
    connect(tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(recordWasClicked()));
    connect(deleteButton,SIGNAL(clicked(bool)),this,SLOT(deleteRecord()));
    connect(addButton,SIGNAL(clicked(bool)),this,SLOT(changeSubMenuState()));
    connect(confirmAdditionButton,SIGNAL(clicked(bool)),this,SLOT(addRecord()));
    connect(model,SIGNAL(failure(QSqlError)),this,SLOT(errorHandler(QSqlError)));
    connect(tableView->itemDelegate(),SIGNAL(closeEditor(QWidget*,QAbstractItemDelegate::EndEditHint)),this,SLOT(editRecord()));
    connect(tableView->itemDelegate(),SIGNAL(closeEditor(QWidget*,QAbstractItemDelegate::EndEditHint)),this,SLOT(changeControlsState()));
    connect(tableView->selectionModel(),SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(changedFrom(QItemSelection)));
    connect(tableView->model(),SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(changedTo(QModelIndex)));
}





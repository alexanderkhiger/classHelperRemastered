#include "fileprocessingview.h"

FileProcessingView::FileProcessingView(QString uID, QueryService *service) {
    directory = "";
    buffer = "";
    errorCount = 0;

    receivedID = uID;
    this->service = service;
    model = new FileProcessingModel(receivedID, service);
    qDebug() << "before creating ui";
    createUI();
    qDebug() << "afterCreatingUI";

    connect(chooseFileButton, SIGNAL(pressed()), this, SLOT(chooseFile()));
    connect(startButton, SIGNAL(pressed()), this, SLOT(processFile()));

    connect(model,SIGNAL(processingFinished()),this,SLOT(completionHandler()));
    connect(model,SIGNAL(sendInformation(QString)),this,SLOT(informationReceived(QString)));
    connect(model,SIGNAL(sendProgress(int)),this,SLOT(progressChanged(int)));
    connect(model,SIGNAL(failure(QSqlError)),this,SLOT(failureHandler(QSqlError)));
}

void FileProcessingView::createUI() {
    this->setMinimumHeight(250);
    this->resize(300,250);

    skipAllCheck = new QCheckBox;
    skipAllCheck->setText(tr("Добавить все, как есть"));

    chooseFileButton = new QPushButton(tr("Выбрать файл"));
    startButton = new QPushButton(tr("Начать обработку"));

    startButton->setEnabled(false);

    chooseFileButton->setMinimumWidth(150);
    startButton->setMinimumWidth(150);

    chooseFileButton->setMaximumWidth(150);
    startButton->setMaximumWidth(150);

    chosenFile = new QLineEdit;
    chosenFile->setReadOnly(true);
    processingProgress = new QProgressBar;

    chosenFile->setMinimumWidth(150);
    processingProgress->setMinimumWidth(150);

    errorCounterLE = new QLineEdit;
    errorCounterLE->setReadOnly(true);

    errorCounterLabel = new QLabel(tr("Количество ошибок"));

    errorCounterLabel->setMinimumWidth(150);
    errorCounterLabel->setAlignment(Qt::AlignCenter);

    actionsLog = new QTextEdit;
    actionsLog->setReadOnly(true);

    topHLayout = new QHBoxLayout;
    middleHLayout = new QHBoxLayout;
    bottomHLayout = new QHBoxLayout;
    vLayout = new QVBoxLayout;

    topHLayout->addWidget(chooseFileButton);
    topHLayout->addWidget(chosenFile);
    middleHLayout->addWidget(startButton);

    middleHLayout->addWidget(skipAllCheck);

    middleHLayout->addWidget(processingProgress);
    bottomHLayout->addWidget(errorCounterLabel);
    bottomHLayout->addWidget(errorCounterLE);
    vLayout->addLayout(topHLayout);
    vLayout->addLayout(middleHLayout);
    vLayout->addWidget(actionsLog);
    vLayout->addLayout(bottomHLayout);

    this->setLayout(vLayout);

    this->setWindowTitle(tr("Добавление файла"));
}

void FileProcessingView::completionHandler() {
    QMessageBox::StandardButton infoMsg;
    infoMsg = QMessageBox::information(this, tr("Оповещение"), tr("Обработка завершена!"), QMessageBox::Ok);
    chooseFileButton->setEnabled(1);
    startButton->setEnabled(1);
    skipAllCheck->setEnabled(1);
}

void FileProcessingView::failureHandler(QSqlError error) {
    actionsLog->append(error.text());
    errorCount++;
    errorCounterLE->setText(QString::number(errorCount));
}

void FileProcessingView::chooseFile() {
    buffer = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "C:/", tr("Text files (*.txt *.rtf)"));
    if (buffer != "") {
        directory = buffer;
    }
    chosenFile->setText(directory);
    if (chosenFile->text()!="") {
        startButton->setEnabled(true);
    }
    else {
        startButton->setEnabled(false);
    }
}

void FileProcessingView::processFile() {
    errorCount=0;
    actionsLog->clear();
    chooseFileButton->setEnabled(0);
    startButton->setEnabled(0);
    skipAllCheck->setEnabled(0);
    errorCounterLE->setText(QString::number(errorCount));
    model->processData(directory, skipAllCheck->isChecked());
}

void FileProcessingView::progressChanged(int percentage) {
    processingProgress->setValue(percentage);
}

void FileProcessingView::informationReceived(QString info) {
    actionsLog->append(info);
}

void FileProcessingView::clear() {
    chosenFile->clear();
    directory = "";
    startButton->setEnabled(false);
    actionsLog->clear();
    errorCounterLE->clear();
}











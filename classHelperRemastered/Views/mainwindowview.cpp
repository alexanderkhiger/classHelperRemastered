#include "mainwindowview.h"

MainWindowView::MainWindowView(QueryService *service, QString uID, QString uName, QString uShortname, QWidget *parent) {
    this->service = service;
    this->parent = parent;
    receivedID = uID;
    receivedName = uName;
    receivedShortname = uShortname;
    createUI();
}

void MainWindowView::createUI() {
    leftBar = new QToolBar;
    leftBar->setMovable(false);
    leftBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QToolButton *distributionTool = new QToolButton;
    QToolButton *tableEditorTool = new QToolButton;
    QToolButton *outputTool = new QToolButton;
    QToolButton *fileProcessingTool = new QToolButton;

    distributionTool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    distributionTool->setIcon(style()->standardIcon(QStyle::SP_FileDialogContentsView));
    distributionTool->setText(tr("Нагрузка"));
    distributionTool->setFixedSize(70,60);
    distributionTool->setToolTip(tr("Распределение нагрузки по преподавателям"));
    connect(distributionTool,SIGNAL(clicked(bool)),this,SLOT(setWorkFieldAsCentral()));

    tableEditorTool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tableEditorTool->setIcon(style()->standardIcon(QStyle::SP_FileDialogDetailedView));
    tableEditorTool->setText(tr("Редактор"));
    tableEditorTool->setFixedSize(70,60);
    tableEditorTool->setToolTip(tr("Редактор таблиц (словарей)"));
    connect(tableEditorTool,SIGNAL(clicked(bool)),this,SLOT(setTableEditorAsCentral()));

    outputTool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    outputTool->setIcon(style()->standardIcon(QStyle::SP_FileIcon));
    outputTool->setText(tr("Отчеты"));
    outputTool->setFixedSize(70,60);
    outputTool->setToolTip(tr("Получение отчета"));
    connect(outputTool,SIGNAL(clicked(bool)),this,SLOT(setOutputToFileAsCentral()));

    fileProcessingTool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    fileProcessingTool->setIcon(style()->standardIcon(QStyle::SP_FileIcon));
    fileProcessingTool->setText(tr("Обработка"));
    fileProcessingTool->setFixedSize(70,60);
    fileProcessingTool->setToolTip(tr("Обработка файла"));
    connect(fileProcessingTool,SIGNAL(clicked(bool)),this,SLOT(setFileProcessingAsCentral()));

    leftBar->addWidget(distributionTool);
    leftBar->addWidget(tableEditorTool);
    leftBar->addWidget(outputTool);
    leftBar->addWidget(fileProcessingTool);

    this->addToolBar(Qt::LeftToolBarArea,leftBar);

    setMinimumHeight(500);
    setMinimumWidth(500);

    fileMenu = new QMenu(tr("Файл"));

    this->menuBar()->addMenu(fileMenu);

    backToUniversityList = new QAction(tr("Выбор университета"), this);
    backToUniversityList->setStatusTip(tr("Назад к выбору университета"));
    fileMenu->addAction(backToUniversityList);

    connect(backToUniversityList,SIGNAL(triggered(bool)),this,SLOT(back()));

    setWindowTitle(QString(tr("Time Tracker | Название университета: %1 | Аббревиатура: %2")).arg(receivedName).arg(receivedShortname));

}

void MainWindowView::back() {
    parent->show();
    close();
}

void MainWindowView::setWorkFieldAsCentral() {
//    if (centralWidget()->objectName()!="workfield") {
//        workField = new WorkFieldView(receivedID, receivedName, receivedShortname);
//        workField->setObjectName("workField");
//        this->setCentralWidget(myWorkField);
//    }
}

void MainWindowView::setTableEditorAsCentral() {
//    if (centralWidget()->objectName()!="tableEditor") {
//        tableEditor = new TableEditorView(receivedID, receivedName, receivedShortname);
//        tableEditor->setObjectName("tableEditor");
//        this->setCentralWidget(tableEditor);
//    }
}

void MainWindowView::setOutputToFileAsCentral() {
//    if (centralWidget()->objectName()!="outputToFile") {
//        outputToFile = new OutputToFileView(receivedID, receivedName, receivedShortname);
//        outputToFile->setObjectName("outputToFile");
//        this->setCentralWidget(outputToFile);
//    }
}

void MainWindowView::setFileProcessingAsCentral() {
//    if (centralWidget()->objectName()!="fileProcessing") {
//        fileProcessing = new FileProcessingView(receivedID, receivedName, receivedShortname);
//        fileProcessing->setObjectName("fileProcessing");
//        this->setCentralWidget(fileProcessing);
//    }
}



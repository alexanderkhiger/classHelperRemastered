#ifndef FILEPROCESSINGVIEW_H
#define FILEPROCESSINGVIEW_H

#include <QWidget>

#include <Models/CentralWidgets/fileprocessingmodel.h>
#include <Services/queryservice.h>

#include <QString>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QFileDialog>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QCheckBox>

class FileProcessingView : public QWidget {
    Q_OBJECT

public:
    explicit FileProcessingView(QString uID, QueryService *service);

private slots:
    void createUI();
    void completionHandler();
    void failureHandler(QSqlError error);

    void chooseFile();
    void processFile();

    void progressChanged(int percentage);
    void informationReceived(QString info);

    void clear();

private:
    QueryService *service;
    QString receivedID;
    FileProcessingModel *model;

    QString directory;
    QString buffer;
    int errorCount;

    QPushButton *chooseFileButton;
    QPushButton *startButton;

    QLineEdit *chosenFile;
    QLineEdit *errorCounterLE;

    QCheckBox *skipAllCheck;

    QLabel *errorCounterLabel;

    QTextEdit *actionsLog;

    QHBoxLayout *topHLayout;
    QHBoxLayout *middleHLayout;
    QHBoxLayout *bottomHLayout;
    QVBoxLayout *vLayout;

    QProgressBar *processingProgress;

    QMessageBox *msg;
};

#endif // FILEPROCESSINGVIEW_H

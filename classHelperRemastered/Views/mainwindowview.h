#ifndef MAINWINDOWVIEW_H
#define MAINWINDOWVIEW_H

#include <QMainWindow>
#include <QToolBar>
#include <QToolButton>
#include <QStyle>
#include <QMenu>
#include <QMenuBar>

class MainWindowView : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindowView(QString uID, QString uName, QString uShortname, QWidget *parent);

signals:

private slots:
    void createUI();
    void back();
    void setWorkFieldAsCentral();
    void setTableEditorAsCentral();
    void setOutputToFileAsCentral();
    void setFileProcessingAsCentral();

public slots:

private:

    QString receivedID;
    QString receivedName;
    QString receivedShortname;
    QWidget *parent;

    QToolBar *leftBar;

    QMenu *fileMenu;

    QAction *backToUniversityList;

};

#endif // MAINWINDOWVIEW_H

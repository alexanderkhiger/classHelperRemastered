#ifndef MAINWINDOWVIEW_H
#define MAINWINDOWVIEW_H

#include <QMainWindow>

class MainWindowView : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindowView(QString uID, QString uName, QString uShortname, QWidget *ref, QWidget *parent = 0);

signals:

public slots:
};

#endif // MAINWINDOWVIEW_H

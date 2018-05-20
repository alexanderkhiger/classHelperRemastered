#ifndef COMMONDATABASETABLEVIEW_H
#define COMMONDATABASETABLEVIEW_H

#include <Components/customtableview.h>
#include <Services/queryservice.h>

#include <QWidget>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QHeaderView>
#include <QLineEdit>
#include <QMessageBox>

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>

class CommonDatabaseTableView: public QWidget {
    Q_OBJECT

protected:
    QGroupBox *workfield;
    QGroupBox *alwaysShownSubMenu;
    QGroupBox *togglableSubMenu;

    CustomTableView *tableView;

    QSqlTableModel *tableModel;

    bool isSubMenuActive;
    bool areControlsActive;

    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *confirmAdditionButton;
    QPushButton *confirmChoiceButton;
    QPushButton *exitButton;

    QDialogButtonBox *buttonBox;

    QueryService *service;

signals:
    void failure(QSqlError error);

private slots:
    virtual void createUI() = 0;
    virtual void changeSubMenuState() = 0;
    virtual void resizeTable() = 0;
    virtual void changeControlsState() = 0;

    virtual void receiveModel() = 0;
    virtual void setModel(QSqlTableModel *model) = 0;

    virtual void recordWasClicked() = 0;

    virtual void deleteRecord() = 0;
    virtual void addRecord() = 0;
    virtual void editRecord() = 0;

    virtual void successHandler() = 0;
    virtual void errorHandler(QSqlError error) = 0;
};

#endif // COMMONDATABASETABLEVIEW_H

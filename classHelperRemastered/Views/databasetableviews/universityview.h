#ifndef UNIVERSITYVIEW_H
#define UNIVERSITYVIEW_H

#include <Views/DatabaseTableViews/commondatabasetableview.h>
#include <Models/DatabaseTableModels/universitymodel.h>
#include <Views/mainwindowview.h>

class UniversityView : public CommonDatabaseTableView {
    Q_OBJECT

public:
    UniversityView(QueryService *service);

private:
    virtual bool UniversityView::eventFilter(QObject *obj, QEvent *event);

    QLineEdit *nameField;
    QLineEdit *shortNameField;

    QVBoxLayout *viewLayout;
    QHBoxLayout *alwaysShownSubMenuLayout;
    QHBoxLayout *togglableSubMenuLayout;
    QVBoxLayout *workfieldLayout;

    UniversityModel *model;

    QString universityBeforeUpdate;
    QString universityAfterUpdate;

signals:
    void failure(QSqlError error);

private slots:
    void createUI();
    void changeSubMenuState();
    void resizeTable();
    void changeControlsState();

    void receiveModel();
    void setModel(QSqlTableModel *model);

    void recordWasClicked();

    void deleteRecord();
    void addRecord();
    void editRecord();

    void completionHandler();
    void failureHandler(QSqlError error);

    void changedFrom(const QItemSelection &selected);
    void changedTo(const QModelIndex &bIndex);

    void createConnections();
};


#endif // UNIVERSITYVIEW_H

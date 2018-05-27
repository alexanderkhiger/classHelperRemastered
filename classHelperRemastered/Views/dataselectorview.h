#ifndef DATASELECTORVIEW_H
#define DATASELECTORVIEW_H

#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHeaderView>
#include <QLabel>
#include <Services/queryservice.h>

class DataSelectorView {
    Q_OBJECT

public:
    DataSelectorView(QueryService *service,
                     QString tableName,
                     DataSelectorView::receivedFacultyName = 0,
                     QString receivedSpecialtyName = 0,
                     QString receivedDisciplineName = 0,
                     QString uID = 0,
                     int alwaysInsert = 0);

private:
    QTableView *myTableView;
    QVBoxLayout *externalVLayout;
    QHeaderView *hHeader;
    QPushButton *createButton;
    QLabel *topLabel;

    QSqlTableModel *facultyModel;
    QSqlTableModel *specialtyModel;
    QSqlTableModel *disciplineModel;

    int faculty_id;
    int specialty_id;
    int discipline_id;

    QueryService *service;

    QString receivedID;
    QString facultyName;
    QString specialtyName;
    QString disciplineName;

private slots:
    void setFacultyModel(QSqlTableModel *model);
    void setSpecialtyModel(QSqlTableModel *model);
    void setDisciplineModel(QSqlTableModel *model);
    void resizeTable();
    void setData(QModelIndex index);
    void createButtonClicked();
    void createUI();
};

#endif // DATASELECTORVIEW_H

#ifndef UNIVERSITYMODEL_H
#define UNIVERSITYMODEL_H

#include <QObject>
#include <Models/DatabaseTableModels/commondatabasetablemodel.h>

class UniversityModel : public CommonDatabaseTableModel {
    Q_OBJECT

public:
    explicit UniversityModel(QueryService *service);

private:
    QueryService *service;

signals:
    void tableModelReceived(QSqlTableModel *model);

public slots:
    void receiveModel(QString tableName);
    void performQuery(QSqlTableModel *model, OperationType type, int row, QString arg1 = 0, QString arg2 = 0);
};

#endif // UNIVERSITYMODEL_H

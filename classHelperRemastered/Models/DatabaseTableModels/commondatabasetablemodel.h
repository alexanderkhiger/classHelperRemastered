#ifndef COMMONDATABASETABLEMODEL_H
#define COMMONDATABASETABLEMODEL_H

#include <Services/queryservice.h>
#include <QSqlError>
#include <QSqlTableModel>

class CommonDatabaseTableModel: public QObject {
    Q_OBJECT

public:
    enum OperationType {
        deleteRecord,
        insertRecord,
        updateRecord
    };

private:
    QueryService *service;

signals:
    void failure(QSqlError error);

public slots:
    virtual void receiveModel(QString tableName) = 0;
};

#endif // COMMONDATABASETABLEMODEL_H

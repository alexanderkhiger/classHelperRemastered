#ifndef QUERYSERVICE_H
#define QUERYSERVICE_H

#include <QObject>
#include <QDebug>
#include <exception.h>

#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRecord>

#include <QList>
#include <QFile>

class QueryService : public QObject {
    Q_OBJECT
public:
    explicit QueryService();

private:
    QString connectionName;
    QString driverName;
    QSqlDatabase db;

signals:

public slots:
    void authorize(const QString login, const QString password, const QString database, const QString hostname);
};

#endif // QUERYSERVICE_H

#include "queryservice.h"

QueryService::QueryService() {
    connectionName = "dbConnection";
    driverName = "QMYSQL";

    if (QSqlDatabase::contains(connectionName))
        db = QSqlDatabase::database(connectionName);
    else
        db = QSqlDatabase::addDatabase(driverName,connectionName);
}

void QueryService::authorize(const QString login, const QString password, const QString database, const QString hostname) {
    db.close();
    db.setHostName(hostname);
    db.setDatabaseName(database);
    db.setUserName(login);
    db.setPassword(password);
    if (!db.open())
        throw Exception(tr("Проверьте правильность введенных данных"));
}

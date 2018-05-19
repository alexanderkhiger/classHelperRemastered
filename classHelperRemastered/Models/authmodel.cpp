#include "authmodel.h"

AuthModel::AuthModel(QueryService *service) {
    this->service = service;
}

void AuthModel::authorize(const QString login, const QString password, const QString database, const QString hostname) {
    try {
        service->authorize(login, password, database, hostname);
    }
    catch(Exception &e) {
        emit failure(e.getErrorInfo());
        return;
    }
    emit success();
}

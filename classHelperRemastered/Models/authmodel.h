#ifndef AUTHMODEL_H
#define AUTHMODEL_H

#include <Services/queryservice.h>

#include <QObject>

class AuthModel : public QObject {
    Q_OBJECT

public:
    explicit AuthModel(QueryService *service);

private:
    QueryService *service;

signals:
    void failure(const QString failure);
    void success();

public slots:
    void authorize(const QString login, const QString password, const QString database, const QString hostname);
};

#endif // AUTHMODEL_H

#ifndef AUTHMODEL_H
#define AUTHMODEL_H

#include <Services/queryservice.h>

#include <QObject>

class AuthModel : public QObject
{
    Q_OBJECT

public:
    explicit AuthModel(QueryService *service);

private:
    QueryService *service;

signals:

public slots:
    void authorize();
};

#endif // AUTHMODEL_H

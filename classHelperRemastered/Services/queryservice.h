#ifndef QUERYSERVICE_H
#define QUERYSERVICE_H

#include <QObject>

class QueryService : public QObject
{
    Q_OBJECT
public:
    explicit QueryService(QObject *parent = nullptr);

signals:

public slots:
};

#endif // QUERYSERVICE_H
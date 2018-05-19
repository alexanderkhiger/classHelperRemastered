#ifndef QUERYSERVICE_H
#define QUERYSERVICE_H

#include <QObject>

class QueryService : public QObject {
    Q_OBJECT
public:
    explicit QueryService();

signals:
    void error(const QString error);

public slots:
};

#endif // QUERYSERVICE_H

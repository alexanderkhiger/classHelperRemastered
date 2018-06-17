#ifndef EXCEPTION_H
#define EXCEPTION_H


#include <QObject>
#include <QSqlError>

class Exception {

public:
    Exception(QSqlError errorInfo) {
        this->errorInfo = errorInfo;
    }
    QSqlError getErrorInfo() {
        return this->errorInfo;
    }
private:
    QSqlError errorInfo;
};

#endif // EXCEPTION_H

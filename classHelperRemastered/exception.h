#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QObject>

class Exception {

public:
    Exception(QString errorInfo) {
        this->errorInfo = errorInfo;
    }
    QString getErrorInfo() {
        return this->errorInfo;
    }
private:
    QString errorInfo;
};

#endif // EXCEPTION_H

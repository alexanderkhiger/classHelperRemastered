#ifndef FILEPROCESSINGMODEL_H
#define FILEPROCESSINGMODEL_H

#include <QObject>
#include <Services/queryservice.h>

class FileProcessingModel : public QObject
{
    Q_OBJECT

public:
    explicit FileProcessingModel(QString uID, QueryService *service);

signals:
    void sendProgress(const int percentage);
    void processingFinished();
    void sendInformation(const QString info);

public slots:
    void processData(QString directory, bool isSkippingAll);

private:
    QueryService *service;
    QString receivedID;
};

#endif // FILEPROCESSINGMODEL_H

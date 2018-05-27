#include "fileprocessingmodel.h"

FileProcessingModel::FileProcessingModel(QString uID, QueryService *service) {
    receivedID = uID;
    this->service = service;
}

void FileProcessingModel::processData(QString directory, bool isSkippingAll) {

}

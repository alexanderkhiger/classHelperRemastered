#include "universitymodel.h"

UniversityModel::UniversityModel(QueryService *service) {
    this->service = service;
}

void UniversityModel::receiveModel(QString tableName) {
    emit tableModelReceived(service->getTableModel(tableName));
}

void UniversityModel::performQuery(QSqlTableModel *model, OperationType type, int row, QString arg1, QString arg2) {
    if (type == deleteRecord) {
        model->removeRow(row);
        if (!model->submitAll()) {
            emit failure(model->lastError().text());
            model->revertAll();
        }
    }
    else if (type == insertRecord) {
        const int rowNumber = model->rowCount();
        model->insertRows(rowNumber, 1);
        model->setData(model->index(rowNumber, 1), arg1);
        model->setData(model->index(rowNumber, 2), arg2);
        if (!model->submitAll()) {
            emit failure(model->lastError().text());
            model->revertAll();
        }
    }
}

#ifndef CUSTOMSQLQUERYMODEL_H
#define CUSTOMSQLQUERYMODEL_H

#include <QObject>
#include <QWidget>
#include <QSqlQueryModel>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QMimeData>

class CustomSqlQueryModel : public QSqlQueryModel {
    Q_OBJECT

public:
    CustomSqlQueryModel() {}

    Qt::DropActions CustomSqlQueryModel::supportedDropActions() const {
        return Qt::CopyAction | Qt::MoveAction;
    }

    Qt::ItemFlags CustomSqlQueryModel::flags(const QModelIndex &index) const {
        Qt::ItemFlags defaultFlags = QSqlQueryModel::flags(index);
        if (index.isValid())
            return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | defaultFlags |Qt::ItemIsSelectable;
        return defaultFlags;
    }

    virtual bool CustomSqlQueryModel::canDropMimeData(const QMimeData, Qt::DropAction, int, int, const QModelIndex) const {
        return true;
    }


    virtual bool CustomSqlQueryModel::dropMimeData(const QMimeData, Qt::DropAction, int, int, const QModelIndex &parent) {
        emit targetIndex(parent);
        return true;
    }

signals:
    void targetIndex(const QModelIndex &index);
};

#endif // CUSTOMSQLQUERYMODEL_H

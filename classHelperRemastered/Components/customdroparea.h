#ifndef CUSTOMDROPAREA_H
#define CUSTOMDROPAREA_H

#include <QObject>
#include <QLabel>
#include <QDragEnterEvent>
#include <QMimeData>

class CustomDropArea : public QLabel {
    Q_OBJECT

public:
    CustomDropArea();

public slots:
    void clear();

signals:
    void itemDropped(const QObject *myObject = 0, const QMimeData *mimeData = 0);
    void areaCleared();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dropEvent(QDropEvent *event) override;

private slots:
    void createUI();

private:
    QLabel *label;
};

#endif // CUSTOMDROPAREA_H

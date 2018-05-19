#ifndef CUSTOMTABLEVIEW_H
#define CUSTOMTABLEVIEW_H

#include <QObject>
#include <QWidget>
#include <QTableView>
#include <QKeyEvent>

class CustomTableView : public QTableView {
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event) {
        switch(event->key()) {
        case Qt::Key_Tab:
            break;
        default:
            QTableView::keyPressEvent(event);
        }
    }

public:
    CustomTableView(){}
    ~CustomTableView(){}
};

#endif // CUSTOMTABLEVIEW_H

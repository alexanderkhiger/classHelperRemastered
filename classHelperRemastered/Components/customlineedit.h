#ifndef CUSTOMLINEEDIT_H
#define CUSTOMLINEEDIT_H

#include <QObject>
#include <QLineEdit>
#include <QWidget>
#include <QToolButton>
#include <QStyle>
#include <QLabel>

class CustomLineEdit : public QLineEdit {
    Q_OBJECT

public:
    CustomLineEdit();

protected:
    void resizeEvent(QResizeEvent *);

signals:
    void needInfo();

private slots:
    void changeClearButtonState(const QString text);
    void createUI();

private:
    QToolButton *clearButton;
    QToolButton *chooseButton;
};


#endif // CUSTOMLINEEDIT_H

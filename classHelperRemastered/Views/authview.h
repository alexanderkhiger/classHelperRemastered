#ifndef AUTHVIEW_H
#define AUTHVIEW_H

#include <Services/queryservice.h>
#include <Models/authmodel.h>

#include <QWidget>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

class AuthView : public QWidget {
    Q_OBJECT

public:
    AuthView(QueryService *service);
    ~AuthView();

private:
    QPushButton *authButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
    QLineEdit *usernameField;
    QLineEdit *passwordField;
    QLineEdit *hostnameField;
    QLineEdit *databaseField;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLabel *hostnameLabel;
    QLabel *databaseLabel;
    QTextEdit *actionsLog;
    QVBoxLayout *externalVLayout;
    QVBoxLayout *internalLeftVLayout;
    QVBoxLayout *internalRightVLayout;
    QHBoxLayout *internalHLayout;
    AuthModel *model;

private slots:
    void createUI();
    void authorize();
};

#endif // AUTHVIEW_H

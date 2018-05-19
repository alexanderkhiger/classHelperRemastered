#include <Views/authview.h>
#include <Services/queryservice.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QueryService *service = new QueryService;
    AuthView *window = new AuthView(service);
    window->show();
    return a.exec();
}

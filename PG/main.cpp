#include "mainwindow.h"
#include "login.h"
#include <QApplication>
//changed by linux
//changed again
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login l;
    l.show();

    return a.exec();
}

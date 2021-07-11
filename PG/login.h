#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

signals:
    void ok();

private slots:

    void on_okButton_clicked();

    void on_exitButon_clicked();

    void haveText();

    void showOk();

private:
    Ui::Login *ui;
    MainWindow *w;
};

#endif // LOGIN_H

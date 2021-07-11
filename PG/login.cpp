#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QRegExp>
#include <QRegExpValidator>
#include <QDialog>
#include <QDebug>
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->userEdit->setClearButtonEnabled(true);
    ui->passwordEdit->setClearButtonEnabled(true);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    QRegExp regExp("[0-9]{0,8}");
    ui->passwordEdit->setValidator(new QRegExpValidator(regExp,this));
    ui->okButton->setEnabled(false);
    connect(ui->userEdit,&QLineEdit::textChanged,this,&Login::haveText);
    connect(ui->passwordEdit,&QLineEdit::textChanged,this,&Login::haveText);
    connect(this,&Login::ok,this,&Login::showOk);
}

Login::~Login()
{
    delete ui;
}


void Login::on_okButton_clicked()
{
    this->close();
    w = new MainWindow;
    w->show();
}

void Login::on_exitButon_clicked()
{
    this->close();
}

void Login::haveText()
{
    if(!ui->userEdit->text().isEmpty()&&!ui->passwordEdit->text().isEmpty())
    {
        emit ok();
    }else {
        ui->okButton->setEnabled(false);
    }

}

void Login::showOk()
{
    ui->okButton->setEnabled(true);
}

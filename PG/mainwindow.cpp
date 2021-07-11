#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QTextLayout>
#include <QTextBlock>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextCursor tc = ui->textEdit->textCursor();
    QTextLayout *playout =tc.block().layout();
    QLabel *label = new QLabel;
    label->setText("行:1,列:1");
    connect(ui->textEdit,&QTextEdit::textChanged,
            [=]()
    {
        int a = tc.position()-tc.block().position();//所在列数
        int b = playout->lineForTextPosition(a).lineNumber()+tc.block().firstLineNumber();//所在行数
        label->setText("行:"+QString::number(b+1)+"列:"+QString::number(a+1));
    }
    );
    ui->statusBar->addPermanentWidget(label);
    connect(ui->actionOpen,&QAction::triggered,
            [=]()
    {
        QFileDialog::getOpenFileName(
                    this,
                    "open",
                    "../",
                    "Text(*.text);;all(*.*)"
                    );
    }
            );
}

MainWindow::~MainWindow()
{
    delete ui;
}


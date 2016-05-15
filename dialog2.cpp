
#include "dialog2.h"
#include "ui_dialog2.h"
#include "mainwindow.h"
#include <QLCDNumber>
#include "hitarea.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    QLCDNumber *lcd = new QLCDNumber(parent);
    ui->lcdNumber->display(QString::number(300));
    lcd->setGeometry(900, 500, 600, 600);
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_pushButton_clicked()
{
    this->close();
    //QObject::connect(this,SIGNAL(accepted()),,SLOT(reset()));
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
}

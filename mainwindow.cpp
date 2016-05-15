#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "taiko.h"
#include <Qdialog>
#include <QObject>
#include <QPushButton>
#include <QtMultimedia/QMediaPlayer>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cena = new QMediaPlayer();
    cena->setMedia(QUrl("qrc:/bestmusic/cena.mp3"));
    cena->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_exitButton_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    mdialog = new Dialog(this);
    this->hide();
    mdialog->show();
    mdialog->exec();
    this->show();
}

void MainWindow::on_startButton_clicked()
{
    Taiko *taiko = new Taiko();
    cena->stop();
    nice = new QMediaPlayer();
    nice->setMedia(QUrl("qrc:/bestmusic/nice.wav"));
    nice->play();


    this->hide();
    taiko->show();
}


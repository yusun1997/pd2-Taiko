#include "taiko.h"
#include "hitarea.h"
#include "drum1.h"
#include "drum2.h"
#include "mainwindow.h"
#include <QApplication>
#include <QGuiApplication>
#include <QtMultimedia/QMediaPlayer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();





    return a.exec();
}

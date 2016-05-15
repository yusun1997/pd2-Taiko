#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QWidget>
#include <QObject>
#include <QImage>
#include <QBrush>
#include "taiko.h"
#include "hitarea.h"
#include "drum1.h"
#include "drum2.h"
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QString>
#include "exp.h"
#include "dialog2.h"
#include <QtMultimedia/QMediaPlayer>

Taiko::Taiko(QWidget *){

scene = new QGraphicsScene();
scene->setSceneRect(0,0,1920,1042);
setBackgroundBrush(QBrush(QImage(":/image/background.jpg")));

setScene(scene);
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(1920,1042);
//set scene
//set a hit area
//make it focused

hitarea = new HitArea();
hitarea->setPos(200,315);
hitarea->setFlag(QGraphicsItem::ItemIsFocusable);
hitarea->setFocus();

scene->addItem(hitarea);


// spawn drums
QTimer * timer = new QTimer();
QObject::connect(timer,SIGNAL(timeout()),hitarea,SLOT(spawn()));
timer->start(1200);

Taiko::timeleft();





show();
}

void Taiko::timeleft()
{
    QTimer *timer = new QTimer(this);
    QLCDNumber *lcd = new QLCDNumber(this);
    lcd->setGeometry(1100,10,300,200);
    connect(timer, &QTimer::timeout, [=]()
    {
    static int sec = 30;
    lcd->display(QString::number(sec--));
    if(sec <= -2){
        this->close();
        Dialog2 *dialog2 = new Dialog2();
        dialog2->show();
        connect(timer,&QTimer::timeout,[=](){
            sec = 30;
        });
        nice = new QMediaPlayer();
        nice->setMedia(QUrl("qrc:/bestmusic/nice.wav"));
        if (nice->state() == QMediaPlayer::PlayingState){
                    nice->setPosition(0);
                }
    }
        });
    timer->start(1000);

}




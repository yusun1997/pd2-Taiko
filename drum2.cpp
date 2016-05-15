#include "drum2.h"
#include <QTimer>
#include <QGraphicsScene>

#include <QDebug>
Drum2::Drum2(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

   setPos(1920,315);
   //setRect(19200,315,200,200);
   setPixmap(QPixmap(":/image/vic.png"));

   // make/connect a timer to move()
   QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(move()));

   // start the timer
   timer->start(20);
}

void Drum2::move()
{
    //auto move
    setPos(x()-10,y());
    if (pos().x()<50){

    delete this;
    }
}

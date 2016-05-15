#include "drum1.h"
#include <QTimer>
#include <QGraphicsScene>

#include <QDebug>
Drum1::Drum1(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){

   setPixmap(QPixmap(":/image/drum1-fix.png"));
   setPos(1920,315);
   //setRect(1920,315,200,200);
   // make/connect a timer to move() the drum every so often
   QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(move()));

   // start the timer
   timer->start(20);
}

void Drum1::move()
{
    //auto move
    setPos(x()-10,y());
    if (pos().x()<50){

    delete this;
    }
}

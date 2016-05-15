#include "hitarea.h"
#include "drum1.h"
#include "drum2.h"
#include "taiko.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QPixmap>
#include <QImage>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <stdlib.h>
#include <time.h>
#include <QList>
#include <typeinfo>
#include <QtMultimedia/QMediaPlayer>
#include <QLCDNumber>
#include "exp.h"
#include <QGraphicsTextItem>
#include <QFont>


#include <QDebug>


HitArea::HitArea(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/image/heart.png"));


}

QTimer *timer = new QTimer();
void HitArea::keyPressEvent(QKeyEvent *event)
{

    HitArea * hitarea = new HitArea();

    QList<QGraphicsItem *> colliding_items = collidingItems();
    Drum1 * drum1 = new Drum1();
    Drum2 * drum2 = new Drum2();
    //Exp * exp = new Exp();



    if(event->key() == Qt::Key_J){

       for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Drum1)){
            qDebug() << score ;
            delete colliding_items[i];
                score=score+30;
            //taiko->exp->add();
            setPixmap(QPixmap(":/image/leftheart.png"));

            QObject::connect(timer,SIGNAL(timeout()),hitarea,SLOT(turnback()));
            timer->start(10);
            leftdrum = new QMediaPlayer();
            leftdrum->setMedia(QUrl("qrc:/image/leftdrum.wav"));
            if (leftdrum->state() == QMediaPlayer::PlayingState){
                        leftdrum->setPosition(0);
                    }
                    else if (leftdrum->state() == QMediaPlayer::StoppedState){
                        leftdrum->play();
                    }
        return;
            }
       }
       setPixmap(QPixmap(":/image/leftheart.png"));

       QObject::connect(timer,SIGNAL(timeout()),hitarea,SLOT(turnback()));
       timer->start(10);
       leftdrum = new QMediaPlayer();
       leftdrum->setMedia(QUrl("qrc:/image/leftdrum.wav"));
       if (leftdrum->state() == QMediaPlayer::PlayingState){
                   leftdrum->setPosition(0);
               }
               else if (leftdrum->state() == QMediaPlayer::StoppedState){
                   leftdrum->play();
               }

    }

    else if (event->key() == Qt::Key_K){

       for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Drum2)){

            delete colliding_items[i];
            score = score +30 ;
            //taiko->exp->add();
           // qDebug() << exp->getExp();
            setPixmap(QPixmap(":/image/rightheart.png"));

            QObject::connect(timer,SIGNAL(timeout()),hitarea,SLOT(turnback()));
            timer->start(10);
            rightdrum = new QMediaPlayer();
            rightdrum->setMedia(QUrl("qrc:/image/rightdrum.wav"));
            if (rightdrum->state() == QMediaPlayer::PlayingState){
                        rightdrum->setPosition(0);
                    }
                    else if (rightdrum->state() == QMediaPlayer::StoppedState){
                        rightdrum->play();
                    }

        return;

            }
       }

       setPixmap(QPixmap(":/image/rightheart.png"));

       QObject::connect(timer,SIGNAL(timeout()),hitarea,SLOT(turnback()));
       timer->start(10);
       rightdrum = new QMediaPlayer();
       rightdrum->setMedia(QUrl("qrc:/image/rightdrum.wav"));
       if (rightdrum->state() == QMediaPlayer::PlayingState){
                   rightdrum->setPosition(0);
               }
               else if (rightdrum->state() == QMediaPlayer::StoppedState){
                   rightdrum->play();
               }

    }


}




void HitArea::spawn()
{
    // randomly create the drum

    Drum1 * drum1 = new Drum1();
    Drum2 * drum2 = new Drum2();
    srand(time(NULL));
    int random_number = rand() % 2;

    if(random_number == 0)
    scene()->addItem(drum1);
    if(random_number == 1)
    scene()->addItem(drum2);
}

void HitArea::turnback()
{
    HitArea * hitarea = new HitArea();
    hitarea->setPixmap(QPixmap(":/image/heart.png"));
    timer->stop();
    return;

}



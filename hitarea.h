#ifndef HITAREA_H
#define HITAREA_H

#include <QApplication>
#include "drum1.h"
#include "drum2.h"
#include "exp.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QtMultimedia/QMediaPlayer>
#include <QGraphicsTextItem>


class HitArea:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    HitArea(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent * event);
    int score=0;

public slots:
    void spawn();
    void turnback();
private:

   QMediaPlayer * leftdrum;
   QMediaPlayer * rightdrum;
};

#endif // HITAREA_H

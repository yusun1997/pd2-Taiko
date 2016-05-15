#ifndef TAIKO_H
#define TAIKO_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QWidget>
#include "drum1.h"
#include "drum2.h"
#include "hitarea.h"
#include <QLCDNumber>
#include <QtMultimedia/QMediaPlayer>

class Taiko: public QGraphicsView
{
public:
    Taiko(QWidget * parent = 0);

    QGraphicsScene * scene;
    QGraphicsRectItem * rect;
    QGraphicsView *view;
    HitArea *hitarea;
    void timeleft();

private slots:
    void showtime();

private:
    QMediaPlayer *nice;

};

#endif

#ifndef DRUM1_H
#define DRUM1_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Drum1:public QObject ,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Drum1(QGraphicsItem * parent = 0);
public slots:
    void move();
    //void hitted();


};

#endif // DRUM1_H

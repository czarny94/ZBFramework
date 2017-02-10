#ifndef ENEMY2_H
#define ENEMY2_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QSound>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "SpaceShooter/enemy.h"


class Enemy2:public Enemy//public QObject,public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Enemy2(QPixmap* texture,QObject* parent=0);
    ~Enemy2();
public slots:
    virtual void move();
protected:

    bool heading ; // definiuje w ktorym kierunku sie porusza przeciwnik

signals:
    void shootDown();

};



#endif // ENEMY2_H

#ifndef BULLET_H
#define BULLET_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QSound>
#include <QPixmap>

#include "core/spritemanager.h"
class Bullet:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent=0);
    Bullet(QPixmap* sprite, QSound* sound,QGraphicsItem* parent=0 );
public slots:
    void move();
private:
    QPixmap* mSprite;
    QSound* mSound;


};

#endif // BULLET_H

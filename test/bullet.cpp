#include "bullet.h"
#include "enemy.h"
#include "score.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>


Bullet::Bullet(QGraphicsItem* parent):QGraphicsPixmapItem(parent)
{
    setPixmap(*mTexture);

    QTimer* timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

Bullet::Bullet(QPixmap *texture, QSound *sound, QGraphicsItem *parent):mTexture(texture), mSound(sound),QGraphicsPixmapItem(parent)
{
    setPixmap(*mTexture);

    QTimer* timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    QList<QGraphicsItem*> mcollidingItems=collidingItems();
    for(auto obj:mcollidingItems)
    {
        if(typeid(*obj)==typeid(Enemy))
        {

            mSound->play();
            scene()->removeItem(obj);
            scene()->removeItem(this);


            dynamic_cast<Enemy*>(obj)->deleteLater() ;
            delete this;
            return;
        }
    }

    setPos(x(),y()-10);

    if(pos().y()<0){
        scene()->removeItem(this);
        delete this;
    }
}

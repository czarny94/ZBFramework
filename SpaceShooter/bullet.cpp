#include "bullet.h"
#include "enemy.h"
#include "enemy3.h"
#include "enemy2.h"
#include "sincrasher.h"
#include "score.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>
#include <QDebug>

Bullet::Bullet(QGraphicsItem* parent):QGraphicsPixmapItem(parent)
{
    setPixmap(*mSprite);

    QTimer* timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

Bullet::Bullet(QPixmap *texture, QSound *sound, QGraphicsItem *parent):mSprite(texture), mSound(sound),QGraphicsPixmapItem(parent)
{
    setPixmap(*mSprite);

    QTimer* timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    QList<QGraphicsItem*> mcollidingItems=collidingItems();
    for(auto obj:mcollidingItems)
    {
        if(typeid(*obj)==typeid(SinCrasher))
        {
            mSound->play();
            //scene()->removeItem(obj);
            scene()->removeItem(this);



            //dynamic_cast<Enemy*>(obj)->deleteLater() ;
            dynamic_cast<Enemy*>(obj)->hit() ;

            dynamic_cast<SinCrasher*>(obj)->hit(1);
            deleteLater();

            return;
        }
        if(typeid(*obj)==typeid(Enemy2))
        {
            mSound->play();
           scene()->removeItem(obj);
           scene()->removeItem(this);

           dynamic_cast<Enemy2*>(obj)->deleteLater() ;
            /* TODO: rzutowanie na typy
             * wydaje mi się, że nie jest potrzebne robienie tego w ten sposób,
             * bo dla każdego przeciwnika trzeba by było zrobić innego ifa,
             * istnieje jakieś bardziej dynamiczne rzutowanie typów?
             * próbowałem dynamic_cast<typeid(*obj)> ale nie do końca działa,
             * a niestety nie mam więcej pomysłów
             * w pewnym momencie może się pojawić więcej tych typów,
             * a wtedy taki switch może się okazać szybszym
            */
            deleteLater();
            return;
        }
        if(typeid(*obj)==typeid(Enemy3))
        {
            mSound->play();
            scene()->removeItem(obj);
            scene()->removeItem(this);


            dynamic_cast<Enemy3*>(obj)->deleteLater() ;
            deleteLater();
            return;
        }
    }

    setPos(x(),y()-10);

    if(pos().y()<=0){
        scene()->removeItem(this);
        qDebug() << "removed bullet " << (int)this ;
       deleteLater();
    }
}

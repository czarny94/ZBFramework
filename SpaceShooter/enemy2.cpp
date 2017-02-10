#include "enemy2.h"

#include <cstdlib>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QList>
#include <typeinfo>


#include <QDebug>
#include "SpaceShooter/player/player.h"


Enemy2::Enemy2(QPixmap* texture,QObject* parent):Enemy(texture,parent)
{
    heading = rand()%2 ;
    frame=3;
    tick=0;
}

Enemy2::~Enemy2()
{
    qDebug()<<"enemy destroyed";
}


void Enemy2::move()
{
    if(pos().x() >675 || pos().x() < 26  ) heading = !heading;
    heading ? setPos(x()+1,y()+1) : setPos(x()-1,y()+1) ;


    if(pos().y()>600){

        scene()->removeItem(this);
        deleteLater();
    }
    QList<QGraphicsItem*> mcollidingItems=collidingItems();
    for(auto obj:mcollidingItems)
    {
        if(typeid(*obj)==typeid(Player))
        {

            mSound->play();
            Player* player=dynamic_cast<Player*>(obj);
            player->hit();
            scene()->removeItem(this);

            delete this;
            return;
        }
    }
}





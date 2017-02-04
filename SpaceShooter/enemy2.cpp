#include "enemy2.h"

#include <cstdlib>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QList>
#include <typeinfo>


#include <QDebug>
#include "SpaceShooter/player/player.h"


Enemy2::Enemy2(QPixmap* texture,QObject* parent):QObject(parent),frame(3),tick(0),mSprite(texture)
{



    heading = rand()%2 ;
    width=mSprite->width();
    fWidth=width/frame;
    setPixmap(mSprite->copy(0,0,fWidth,mSprite->height()));
    QTimer* timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    QTimer* animTimer=new QTimer(this);
    connect(animTimer,SIGNAL(timeout()),this,SLOT(anim()));
    timer->start(10);
    animTimer->start(100);

    mSound=new QSound(":/sfx/res/boom.wav"); //TODO: trzeba bedzie dodac inny dzwiek



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

void Enemy2::anim()
{
    int temp=tick%frame;
    setPixmap(mSprite->copy(0+fWidth*temp,0,fWidth,mSprite->height()));
    tick++;
}

void Enemy2::hit(int dmg)
{

}

void Enemy2::attack()
{

}

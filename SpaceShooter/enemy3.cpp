#include "enemy3.h"
#include <cstdlib>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QList>
#include <typeinfo>


#include <QDebug>
#include "SpaceShooter/player/player.h"


Enemy3::Enemy3(QPixmap* texture,QObject* parent):QObject(parent),frame(3),tick(0),mSprite(texture)
{



    heading = 0 ;
    movingleft = rand()%2;
    width=mSprite->width();
    fWidth=width/frame;
    setPixmap(mSprite->copy(0,0,fWidth,mSprite->height()));
    QTimer* timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    QTimer* animTimer=new QTimer(this);
    connect(animTimer,SIGNAL(timeout()),this,SLOT(anim()));
    timer->start(10);
    animTimer->start(100);

    mSound=new QSound(":/sfx/res/boom.wav");



}

Enemy3::~Enemy3()
{
    qDebug()<<"enemy destroyed";
}


void Enemy3::move()
{
    if(heading==0||(heading>=x()&&!movingleft)||(heading<=x()&&movingleft))
    {
        heading =(rand()%200) - 100 ;
        if(heading+x()>=675||heading+x()<=25) heading = - heading ;
        heading += x() ;
        movingleft = !movingleft ;

    }
    !movingleft ? setPos(x()-1,y()+1):setPos(x()+1,y()+1);


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

void Enemy3::anim()
{
    int temp=tick%frame;
    setPixmap(mSprite->copy(0+fWidth*temp,0,fWidth,mSprite->height()));
    tick++;
}

void Enemy3::hit(int dmg)
{

}

void Enemy3::attack()
{

}

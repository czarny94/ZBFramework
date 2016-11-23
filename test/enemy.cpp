#include "enemy.h"
#include <cstdlib>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>



#include <QDebug>


Enemy::Enemy(QPixmap* texture,QObject* parent):QObject(parent),frame(3),tick(0),sheet(texture)
{


    qDebug()<<"kon enemy";

    width=sheet->width();
    fWidth=width/frame;
    setPixmap(sheet->copy(0,0,fWidth,sheet->height()));
    QTimer* timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    QTimer* animTimer=new QTimer(this);
    connect(animTimer,SIGNAL(timeout()),this,SLOT(anim()));
    timer->start(10);
    animTimer->start(100);


    qDebug()<<"kon2 enemy";
}

Enemy::~Enemy()
{
    qDebug()<<"enemy destroyed";
}


void Enemy::move()
{
    setPos(x(),y()+1);


    if(pos().y()>600){

        scene()->removeItem(this);
        deleteLater();
    }
}

void Enemy::anim()
{
    int temp=tick%frame;
    setPixmap(sheet->copy(0+fWidth*temp,0,fWidth,sheet->height()));
    tick++;
}

void Enemy::hit(int dmg)
{

}

void Enemy::attack()
{

}

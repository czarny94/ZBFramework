#include "boss1.h"
#include <cstdlib>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QList>
#include <typeinfo>
#include <QDebug>
#include "SpaceShooter/player/player.h"


Boss1::Boss1(QPixmap* texture,QGraphicsItem *parent):QGraphicsPixmapItem(parent),frame(3),tick(0),mSprite(texture)
{
    //w konstruktorze są po prostu skopiowane wartości które były wewnątrz klasy Enemy,
    //trxzeba by je było pozmieniać w taki sposób, żeby były jakoś rozsądne, bo nie do końca
    //wiem do czego służą
    hp = 25 ;
    heading = 0 ;
    toleft = true ;
    setPixmap(*mSprite);
    QTimer* movetimer = new QTimer() ;
    QTimer* spawntimer = new QTimer() ;
    QTimer* animtimer = new QTimer();
    connect(movetimer,SIGNAL(timeout()),this,SLOT(move()));
    connect(spawntimer,SIGNAL(timeout()),this,SLOT(spawn()));
    connect(animtimer,SIGNAL(timeout()),this, SLOT(anim()));
    movetimer->start(20);
    spawntimer->start(1500);
    animtimer->start(100);
}


void Boss1::takedamage(int damage)
{
    hp -= damage ;
    if(hp<=0)
    {
        scene()->removeItem(this);
        deleteLater();
    }
}

void Boss1::move()
{
    if(heading==0 || (heading<=x()&&toleft) || (heading>=x()&&!toleft))
    {
        heading =(rand()%400) - 200 ;
        if(heading+x()<25||heading+x()>675)
        {
            heading = - heading ;
        }
        heading +=x() ;
        if(heading < x()) toleft = true ;
        else toleft = false ;

    }
    toleft ? setPos(x()-1,y()) : setPos(x()+1,y());
}

void Boss1::spawn()
{
    switch(1 + (rand()%3))
    {
    case 1 :
        // część funkcji która spwanuje przeciwnika pod bossem
        break ;
    case 2 :
        // część funkcji która spwanuje drugiego przciwnika pod bossem
        break ;
    case 3 :
        // część funkcji która spawnuje trzeciego przeciwnika pod bossem
        break ;
    }
}

void Boss1::anim()
{
    int temp=tick%frame;
    setPixmap(mSprite->copy(0+fWidth*temp,0,fWidth,mSprite->height()));
    tick++;
}

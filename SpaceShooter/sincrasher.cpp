#include "enemy.h"
#include "sincrasher.h"
#include <cstdlib>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QList>
#include <typeinfo>
#include <math.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>


#include <QDebug>
#include "SpaceShooter/player/player.h"
#define PI 3.14159265
SinCrasher::SinCrasher(QPixmap* texture,QObject* parent):Enemy(texture, parent)
{
//    SpriteManager* texManager=SpriteManager::getInstance();
//    mSprite = texManager->loadSprite("res/ship6.bmp");
    srand( time( NULL ) );
    xPos = (rand() % 3) * 150;

    this->speed = 1;
    this->mHealth = 2;
    this->enemyType = 1;

}

void SinCrasher::move()
{
    switch (xPos) {
    case 150:
    {
            double tang = (speed)/(x()-((sin(y()*0.5*PI/80))+150 + xPos));
            double degree = atan(tang) * (180/PI);
            setPos((150*sin(y()*0.5*PI/80))+150 + xPos, y() + speed);
            //setRotation(360-degree);
    }
        break;
    case 300:
    {
        double tang = (speed)/(x()-((sin(y()*0.5*PI/80))+150 + xPos));
        double degree = atan(tang) * (180/PI);
        setPos((150*sin(y()*0.5*PI/110))+150 + xPos, y() + speed);
        //setRotation(360-degree);
    }
        break;
    default:
    {
        double tang = (speed)/(x()-((sin(y()*0.5*PI/80))+150 + xPos));
        double degree = atan(tang) * (180/PI);
        setPos((150*sin(y()*0.5*PI/80))+150 + xPos, y() + speed);
        //setRotation(360-degree);
    }
    };


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

            deleteLater();
            return;
        }
    }
}

void SinCrasher::hit(int dmg)
{
    mHealth -= dmg;
    setOpacity(0.65);
    if(mHealth <= 0){
        emit enemyKilled();
        scene()->removeItem(this);
        deleteLater();
    };
}

SinCrasher::~SinCrasher()
{
//    mSprite.reset();
//    SpriteManager::getInstance()->deleteTexture("res/ship6.bmp");
}

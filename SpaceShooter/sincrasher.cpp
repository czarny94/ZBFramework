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
    srand( time( NULL ) );
    xPos = (rand() % 3 + 1) * 150;
    int enemy = rand() % 2 + 1;
    enemyType = 1;
    switch (enemyType) {
    case 1:
        this->speed = 1;
        this->mHealth = 2;
        this->enemyType = 1;
        break;
    case 2:
        this->speed = 50;
        this->mHealth = 2;
        this->enemyType = 2;
        break;
    case 3:
        this->speed = 6;
        this->mHealth = 2;
        this->enemyType = 3;
        break;
    case 4:
        this->speed = 3;
        this->mHealth = 3;
        this->enemyType = 4;
        break;
    default:
        this->speed = 2;
        this->mHealth = 10;
        this->enemyType = 1;
        break;
    };
}

void SinCrasher::move()
{
    //srand( time( NULL ) );
    int move = rand() % 4;
    switch (this->enemyType) {
    case 1:
    {
            double tang = (speed)/(x()-((sin(y()*0.5*PI/80))+150 + xPos));
            double degree = atan(tang) * (180/PI);
            setPos((150*sin(y()*0.5*PI/80))+150 + xPos, y() + speed);
            //setRotation(360-degree);
    }
        break;
    case 2:

            switch (move) {
            case 0:
                if(pos().x() + speed <= 700)
                    setPos(x() + speed, y() + 1);
                else
                    setPos(x() - speed, y() + 1);
                break;
            case 1:
                if(pos().x() - speed >= 0)
                   setPos(x() - speed, y() + 1);
                else
                   setPos(x() + speed, y() + 1);
                break;
            case 2:
                setPos(x() + 1, y() + speed);
                break;
            case 3:
                if(pos().y() - speed >= 0)
                    setPos(x() + 1, y() - speed);
                else
                    setPos(x() + 1, y() + speed);
                break;
            }
        break;
    case 3:
        if(pos().x() < 600)
            setPos(x() + speed + 1, y() + speed);
        break;
    case 4:
        if(pos().x() < 600)
            setPos(x() + speed + 1, y() + speed);
        break;
    default:
        if(pos().x() < 600)
            setPos(x() + speed + 1, y() + speed);
        break;
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

            delete this;
            return;
        }
    }
}

void SinCrasher::hit(int dmg)
{
    mHealth -= dmg;
    if(mHealth <= 0){
         scene()->removeItem(this);
        delete this;
    };
}

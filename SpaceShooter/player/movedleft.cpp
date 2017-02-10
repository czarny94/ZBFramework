#include "movedleft.h"
#include "SpaceShooter/player/player.h"

MovedLeft::MovedLeft(Player* player,QState *parent ):PlayerState(player,parent)
{
    connect(this,SIGNAL(entered()),this,SLOT(setSprite()));
    mTimer=new QTimer(this);
    mTimer->setInterval(25);
    connect(mTimer,SIGNAL(timeout()),this,SLOT(move()));
    connect(this,SIGNAL(exited()),mTimer,SLOT(stop()));
    connect(this,SIGNAL(entered()),mTimer,SLOT(start()));

}


void MovedLeft::moveRight()
{

}

void MovedLeft::move()
{
    if(mPlayer->x()>0){
        mPlayer->setPos(mPlayer->x()-mPlayer->speed,mPlayer->y());
        //mPlayer->setRotation(330);
    }
}

void MovedLeft::moveLeft()
{

}

void MovedLeft::setSprite()
{
    mPlayer->setTexture(Player::SPRITE::LEFT);
}


#include "movedleft.h"
#include "test/player/player.h"

MovedLeft::MovedLeft(Player* player,QState *parent ):PlayerState(player,parent)
{
    connect(this,SIGNAL(entered()),this,SLOT(setTexture()));
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
    if(mPlayer->x()>0)
        mPlayer->setPos(mPlayer->x()-5,mPlayer->y());
}

void MovedLeft::moveLeft()
{

}

void MovedLeft::setTexture()
{
    mPlayer->setTexture(Player::Texture::LEFT);
}


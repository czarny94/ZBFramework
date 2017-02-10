#include "movedright.h"
#include "SpaceShooter/player/player.h"


MovedRight::MovedRight(Player *player, QState *parent):PlayerState(player,parent)
{
    connect(this,SIGNAL(entered()),this,SLOT(setSprite()));
    mTimer=new QTimer(this);
    mTimer->setInterval(25);
    connect(mTimer,SIGNAL(timeout()),this,SLOT(move()));
    connect(this,SIGNAL(exited()),mTimer,SLOT(stop()));
    connect(this,SIGNAL(entered()),mTimer,SLOT(start()));
}

void MovedRight::moveLeft()
{

}

void MovedRight::moveRight()
{


}

void MovedRight::move()
{
    if(mPlayer->x()+100<800){
        mPlayer->setPos(mPlayer->x()+mPlayer->speed,mPlayer->y());
        //mPlayer->setRotation(30);
    }
}



void MovedRight::setSprite()
{
    mPlayer->setTexture(Player::SPRITE::RIGHT);
}

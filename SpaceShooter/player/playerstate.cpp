#include "playerstate.h"
#include "test/player/player.h"
#include <QDebug>

PlayerState::PlayerState(Player* player,QState *parent):QState(parent),mPlayer(player)
{
    connect(this,SIGNAL(entered()),this,SLOT(setSprite()));
    mTimer=new QTimer(this);

    mTimer->start(100);
}

void PlayerState::shoot()
{
   mPlayer->attack();
}

void PlayerState::stopMoving()
{
    qDebug()<<"stop state";
    emit(stop());
}

void PlayerState::moveDown()
{
     mPlayer->setPos(mPlayer->x(),mPlayer->y()+10);
}

void PlayerState::moveUp()
{
    mPlayer->setPos(mPlayer->x(),mPlayer->y()-10);
}



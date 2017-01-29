#include "staticstate.h"
#include "SpaceShooter/player/player.h"

StaticState::StaticState(Player *player, QState *parent):PlayerState(player,parent)
{
    connect(this,SIGNAL(entered()),this,SLOT(setSprite()));
}

void StaticState::moveLeft()
{
    emit(left());
}

void StaticState::moveRight()
{
    emit(right());
}

void StaticState::setSprite()
{
    mPlayer->setTexture(Player::SPRITE::STATIC);
}

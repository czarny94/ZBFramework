#include "staticstate.h"
#include "test/player/player.h"

StaticState::StaticState(Player *player, QState *parent):PlayerState(player,parent)
{
    connect(this,SIGNAL(entered()),this,SLOT(setTexture()));
}

void StaticState::moveLeft()
{
    emit(left());
}

void StaticState::moveRight()
{
    emit(right());
}

void StaticState::setTexture()
{
    mPlayer->setTexture(Player::Texture::STATIC);
}

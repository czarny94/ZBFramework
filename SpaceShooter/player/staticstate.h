#ifndef STATICSTATE_H
#define STATICSTATE_H

#include "test/player/playerstate.h"

class StaticState : public PlayerState
{
public:
    StaticState(Player* player, QState *parent = nullptr);
    virtual void moveLeft();
    virtual void moveRight();
protected slots:
    virtual void setSprite();

};

#endif // STATICSTATE_H

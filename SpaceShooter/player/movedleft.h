#ifndef MOVEDLEFT_H
#define MOVEDLEFT_H


#include "test/player/playerstate.h"

//class Player;


class MovedLeft: public PlayerState
{
    Q_OBJECT
public:
    MovedLeft(Player* player, QState *parent =nullptr);

public slots:
    virtual void moveLeft();
    virtual void moveRight();
    void move();


protected slots:
    void setSprite() ;
private:

};

#endif // MOVEDLEFT_H

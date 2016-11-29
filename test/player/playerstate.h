#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

#include <QState>

class PlayerState : public QState
{
    Q_OBJECT
public:
    virtual void moveLeft()=0;
    virtual void moveRight()=0;
    virtual void moveUp()=0;
    virtual void moveDown()=0;
    virtual void shoot();
    virtual void stopMoving();
    PlayerState();
protected:
    bool createStates();
};

#endif // PLAYERSTATE_H

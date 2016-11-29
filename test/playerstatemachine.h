#ifndef PLAYERSTATEMACHINE_H
#define PLAYERSTATEMACHINE_H
#include <QStateMachine>

#include "test/player.h"

class PlayerStateMachine : public QStateMachine
{
public:
    PlayerStateMachine();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void shoot();
    void stopMoving();
    void setPlayer(Player* player);
protected:
    bool createStates();
    Player* mPlayer;
};

#endif // PLAYERSTATEMACHINE_H

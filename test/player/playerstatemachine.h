#ifndef PLAYERSTATEMACHINE_H
#define PLAYERSTATEMACHINE_H
#include <QStateMachine>
#include "test/player/playerstate.h"

class Player;
class PlayerStateMachine : public QStateMachine
{
    Q_OBJECT
public:
    PlayerStateMachine(Player* player);
    virtual void moveLeft();
    virtual void moveRight();
    virtual void moveUp();
    virtual void moveDown();
    virtual void shoot();
    virtual void stopMoving();
    inline PlayerState* getState()const ;
protected:
    bool createStates();  
    Player* mPlayer;
    PlayerState* mCurrentState;
protected slots:
    void setCurrentState();


};

#endif // PLAYERSTATEMACHINE_H

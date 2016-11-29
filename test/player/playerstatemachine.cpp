#include "playerstatemachine.h"
#include "movedleft.h"
#include "movedright.h"
#include "staticstate.h"
#include <QDebug>

PlayerStateMachine::PlayerStateMachine(Player* player):QStateMachine(),mPlayer(player)
{
    if(!createStates())
        qDebug()<<"nie udało sie utworzyc maszyny statnow: nie utworzono jednego ze stanow";
}

void PlayerStateMachine::moveLeft()
{
    mCurrentState->moveLeft();
}

void PlayerStateMachine::moveRight()
{
    mCurrentState->moveRight();
}

void PlayerStateMachine::moveUp()
{
    mCurrentState->moveUp();
}

void PlayerStateMachine::moveDown()
{
    mCurrentState->moveDown();
}

void PlayerStateMachine::shoot()
{
    mCurrentState->shoot();
}

void PlayerStateMachine::stopMoving()
{
    mCurrentState->stopMoving();
}

PlayerState *PlayerStateMachine::getState() const
{
    return mCurrentState;
}



bool PlayerStateMachine::createStates()
{
   PlayerState* leftState=new MovedLeft(mPlayer,this);
    if(!leftState)
        return false;

    connect(leftState,SIGNAL(entered()),this,SLOT(setCurrentState()));

    PlayerState* rightState=new MovedRight(mPlayer,this);
    if(!rightState)
        return false;

    connect(rightState,SIGNAL(entered()),this,SLOT(setCurrentState()));

    StaticState* staticState=new StaticState(mPlayer,this);
    if(!staticState)
        return false;

    connect(staticState,SIGNAL(entered()),this,SLOT(setCurrentState()));
    setInitialState(staticState);

    staticState->addTransition(staticState,SIGNAL(left()),leftState);
    staticState->addTransition(staticState,SIGNAL(right()),rightState);
    leftState->addTransition(leftState,SIGNAL(stop()),staticState);
    rightState->addTransition(rightState,SIGNAL(stop()),staticState);

    return true;
}

void PlayerStateMachine::setCurrentState()
{
    PlayerState* state;
    state=dynamic_cast<PlayerState*>(sender());
    if(state)
    {
        mCurrentState=state;
    }
}

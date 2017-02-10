#include "agamestate.h"


AGameState::AGameState(QString stateID):mStateID(stateID)//,Engine* engine):mStateID(stateID),mEngine(engine)
{

}

AGameState::~AGameState()
{

}

void AGameState::setID(QString stateID)
{
    mStateID=stateID;
}

#include "gamestatemanager.h"

GameStateManager::GameStateManager(QObject *parent) : QObject(parent)
{

}

void GameStateManager::pushState(AGameState* state)
{
    mStates.push_back(state);
    mStates.back()->onEnter();
}

void GameStateManager::popState()
{
    if (!mStates.empty())
    {
        mStates.back()->onExit();
        mStates.pop_back();

    }
}

void GameStateManager::changeState(AGameState* state)
{
    if (!mStates.empty())
    {
        if (mStates.back()->getStateId() == state->getStateId())
        {
            return;
        }
        else
        {
            mStates.back()->onExit();
            delete mStates.back();
            mStates.pop_back();
        }
    }
    pushState(state);
}

GameStateManager::~GameStateManager()
{
    mStates.clear();
}


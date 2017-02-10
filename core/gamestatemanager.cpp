#include "gamestatemanager.h"

#include <QDebug>

GameStateManager::GameStateManager(QObject *parent) : QObject(parent)
{

}

void GameStateManager::pushState(AGameState* state)
{
    qDebug()<<"push state"<<state->getStateId();
    mStates.push_back(state);
    mStates.back()->onEnter();
    connectSlots(state);

    emit(stateChanged(state));
}

void GameStateManager::popState()
{
    if (!mStates.empty())
    {

        mStates.back()->onExit();
        mStates.back()->disconnect();
        qDebug()<<"pop state"<<mStates.back()->getStateId();
        mStates.pop_back();
    }

    emit (stateChanged(mStates.back()));
}

void GameStateManager::changeState(AGameState* state)
{
    qDebug()<<"change state"<<state->getStateId();
    if (!mStates.empty())
    {
        if (mStates.back()->getStateId() == state->getStateId())
        {
            return;
        }
        else
        {
            AGameState* temp=mStates.back();
            if(temp)
            {
            temp->onExit();
            temp->disconnect();
            mStates.pop_back(); qDebug()<<"pop state";

            qDebug()<<"delete state";temp->deleteLater();
            }

        }
    }
    pushState(state);

}


void GameStateManager::connectSlots(AGameState * state)
{
    connect(state,SIGNAL(changeState(AGameState*)),this,SLOT(changeState(AGameState*)));
    connect(state,SIGNAL(pushState(AGameState*)),this,SLOT(pushState(AGameState*)));
}

AGameState *GameStateManager::getState()
{
    if(mStates.empty())
        return nullptr;
    else
        return mStates.back();
}

GameStateManager::~GameStateManager()
{

    for(auto obj : mStates)
    {
        delete obj;
        //obj->deleteLater();
    }

    mStates.clear();
    qDebug()<<"GSM destr";
}


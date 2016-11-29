#include "engine.h"
#include "test/mainmenu.h"
#include <QDebug>

#include "test/level.h"

Engine::Engine(QObject *parent)
    : QObject(parent)
{
    mStateManager=new GameStateManager(this);
    mCurrentState=nullptr;
    MainMenu* mainMenu=new MainMenu();
    //Level* mLevel=new Level();
    connect(mStateManager,SIGNAL(stateChanged(AGameState*)),this,SLOT(setCurrentState(AGameState*)));
    qDebug()<<"pushuje mm";
    mStateManager->pushState(mainMenu);
    //mStateManager->pushState(mLevel);
}

void Engine::play()
{

    if(mCurrentState)
    {
        mCurrentState->show();
        mCurrentState->play();
    }
    else return;
}

void Engine::setCurrentState(AGameState *state)
{
    if(state)
    {
        mCurrentState=state;
        play();
    }
}

Engine::~Engine()
{
    qDebug()<<"destr engine";
    delete mStateManager;
}

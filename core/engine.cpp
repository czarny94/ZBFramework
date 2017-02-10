#include "engine.h"
#include "SpaceShooter/mainmenu.h"
#include <QDebug>

#include "SpaceShooter/level.h"

Engine::Engine(QObject *parent)
    : QObject(parent)
{
    mainWindow = new QMainWindow();
    //mainWindow->setWindowState(Qt::WindowMaximized);
    mainWindow->setFixedSize(800, 600);
    mainWindow->show();



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
                mainWindow->setCentralWidget(mCurrentState);
    }
}

Engine::~Engine()
{
    qDebug()<<"destr engine";
    delete mStateManager;
    delete mainWindow;
}

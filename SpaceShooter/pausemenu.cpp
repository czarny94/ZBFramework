#include "pausemenu.h"

PauseMenu::PauseMenu():AGameState("pause")
{
    mScene=new QGraphicsScene(this);

    mCamera=new QGraphicsView(mScene,this);

    mNewGameButton=new QPushButton("New Game");//,mCamera);
    connect(mNewGameButton,SIGNAL(clicked(bool)),this,SLOT(newGame()));
    mExitButton=new QPushButton("Exit");//,mCamera);
    connect(mExitButton,SIGNAL(clicked(bool)),this,SLOT(exit()));
}

void PauseMenu::onEnter()
{

}

void PauseMenu::onExit()
{

}

void PauseMenu::play()
{

}

PauseMenu::~PauseMenu()
{

}

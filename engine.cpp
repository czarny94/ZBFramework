#include "engine.h"

Engine::Engine(QWidget *parent)
    : QWidget(parent)
{
    mStateManager=new GameStateManager(this);
}

Engine::~Engine()
{

}

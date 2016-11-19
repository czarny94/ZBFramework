#include "level.h"
#include "test/mainmenu.h"
#include <QDebug>
#include <QTimer>
 Game* game;
Level::Level():AGameState("Level")
{
    qDebug()<<"start kon level";
    mCamera=new Game();
    game=mCamera;
    qDebug()<<"kon level";


}

void Level::onEnter()
{
    qDebug()<<"start onEnter level state";


    mCamera->showNormal();
    qDebug()<<"end onEnter level state";

}

void Level::onExit()
{
    mCamera->hide();


}

void Level::play()
{
    qDebug()<<"play level state";

    mCamera->show();
    qDebug()<<"end play level state";
}



Level::~Level()
{
    mScene->deleteLater();
    mCamera->deleteLater();

}

void Level::test1()
{

    emit(changeState(new MainMenu));
}

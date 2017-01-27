#include "test/gameover.h"
#include "core/spritemanager.h"
#include "test/mainmenu.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <memory>

GameOver::GameOver():AGameState("GameOver")
{
    QGraphicsScene* scene=new QGraphicsScene(0,0,800,600,this);
    QGraphicsView* view=new QGraphicsView(scene);
    scene->setBackgroundBrush(QBrush(*(SpriteManager::getInstance()->loadSprite("res/GameOver.png").get())));
    view->show();
    QTimer* timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(toMain()));
    timer->start(1000);


}

void GameOver::onEnter()
{

}

void GameOver::onExit()
{

}

void GameOver::play()
{

}

void GameOver::toMain()
{
    emit(changeState(new MainMenu));
}

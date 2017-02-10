#include "level2.h"
#include "SpaceShooter/mainmenu.h"
#include "SpaceShooter/gameover.h"
#include <QDebug>
#include <QTimer>
#include <QMediaPlaylist>
#include <QCoreApplication>

#include "SpaceShooter/player/inputplayer.h"
#include "SpaceShooter/player/movedleft.h"
//TODO: zwalnianie aktorow, moze kolejny kontener dla nich ?

Level2::Level2(int mod):Level()
{
    qDebug()<<"start kon level2";
    mode = mod ;
    setID("level12");
    createSpawner( );
    qDebug()<<"kon level2";
}








void Level2::gameOver()
{
    //mScene->addText("GAME OVER");
    emit(changeState(new MainMenu));
}







bool Level2::createSpawner()
{
    qDebug() << "creating spawner";
    EnemyPrototype* enemyProt=new EnemyPrototype(this);
    mSpawner=new GraphicsItemFactory(enemyProt,this);

    mSpawnTimer=new QTimer(this);
    connect(mSpawnTimer,SIGNAL(timeout()),this,SLOT(spawnEnemy2()));
    return true;
}


void Level2::spawnEnemy2()
{

       QGraphicsItem* enemy=mSpawner->create(mode);//
       int randomNumber=rand() %650;
       enemy->setPos(randomNumber+25,0);

       mScene->addItem(enemy); qDebug()<<"add item to scene" ;
}

void Level2::test1()
{

    emit(changeState(new MainMenu));
}

#include "level.h"
#include "SpaceShooter/mainmenu.h"
#include "SpaceShooter/gameover.h"
#include <QDebug>
#include <QTimer>
#include <QMediaPlaylist>
#include <QCoreApplication>

#include "SpaceShooter/player/inputplayer.h"
#include "SpaceShooter/player/movedleft.h"
//TODO: zwalnianie aktorow, moze kolejny kontener dla nich ?

Level::Level():AGameState("Level")
{
    qDebug()<<"start kon level";

    createScene();
    createView();
    createSpawner();
    createMediaPlayer();

    mScore=new Score();
    mScore->setPos(x(),y());

    mHealth=new Health();
    mHealth->setPos(mHealth->x(),mHealth->y()+25);

    mScene->addItem(mHealth);
    mScene->addItem(mScore);

    mPlayer=new Player;
    mScene->addItem(mPlayer);
    mPlayer->setPos(400,500);

    //mGui=new GameGUI(this);
    //mScene->addItem(mGui);

    mCamera->setScene(mScene);

//    connect(mPlayer,SIGNAL(entityDead()),this,SLOT(gameOver()));
//    connect(mPlayer,SIGNAL(healthChanges(int)),mHealth,SLOT(set(int)));




    qDebug()<<"kon level";
}

void Level::onEnter()
{
    qDebug()<<"start onEnter level state";


    mCamera->showNormal();
    mediaPlayer->play();

    qDebug()<<"end onEnter level state";

}

void Level::onExit()
{
    mCamera->hide();


}

void Level::play()
{
    qDebug()<<"play level state";

    //mCamera->show();
    mSpawnTimer->start(1000);

    qDebug()<<"end play level state";
}



Level::~Level()
{
    for(auto item:mScene->items()){
            delete item;
        }
        mScene->deleteLater();
    mScene->deleteLater();
    mCamera->deleteLater();
    mSpawner->deleteLater();
    qDebug()<<"destr level";
}

void Level::gameOver()
{
    //mScene->addText("GAME OVER");
    emit(changeState(new MainMenu));
}

bool Level::createScene()
{
     mScene=new QGraphicsScene();

     QImage image(":/img/res/cosmos.jpg");
     mScene->setBackgroundBrush(QBrush(image));

     return true;

}

bool Level::createView()
{
    mCamera=new QGraphicsView(this);
    mCamera->setScene(mScene);

    mCamera->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mCamera->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    mCamera->setFixedSize(800,600);
    mCamera->setSceneRect(0,0,800,600);

    return true;
}

bool Level::createMediaPlayer()
{
    mediaPlayer=new QMediaPlayer(this);
    QMediaPlaylist* playlist=new QMediaPlaylist(this);

    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    playlist->addMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath()+"/res/Subjected_rancor.mp3")); //Ultraviolence - Psycho Drama - 05 - Psycho Drama.mp3 Subjected_rancor.mp3
//
    mediaPlayer->setPlaylist(playlist);
    mediaPlayer->setVolume(50);

    return true;
}

bool Level::createSpawner()
{
    EnemyPrototype* enemyProt=new EnemyPrototype(this);
    mSpawner=new GraphicsItemFactory(enemyProt,this);

    mSpawnTimer=new QTimer(this);
    connect(mSpawnTimer,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    return true;
}

void Level::spawnEnemy()
{

       QGraphicsItem* enemy=mSpawner->create(1);
       int randomNumber=rand() %700;
       enemy->setPos(randomNumber,0);

       mScene->addItem(enemy); qDebug()<<"add item to scene" ;
}

void Level::test1()
{

    emit(changeState(new MainMenu));
}

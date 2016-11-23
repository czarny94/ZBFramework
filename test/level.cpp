#include "level.h"
#include "test/mainmenu.h"
#include <QDebug>
#include <QTimer>
#include <QMediaPlaylist>
#include <QCoreApplication>

Level::Level():AGameState("Level")
{
    qDebug()<<"start kon level";

    createScene();
    createView();
    createSpawner();
    createMediaPlayer();

    mPlayer=new Player;
    mScene->addItem(mPlayer);
    mPlayer->setPos(400,500);

    score=new Score();
    mScene->addItem(score);

    health=new Health();
    health->setPos(health->x(),health->y()+25);
    mScene->addItem(health);

    mCamera->setScene(mScene);

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

    mCamera->show();
    mSpawnTimer->start(1000);

    qDebug()<<"end play level state";
}



Level::~Level()
{
    mScene->deleteLater();
    mCamera->deleteLater();
    mSpawner->deleteLater();
    qDebug()<<"destr level";
}

bool Level::createScene()
{
     mScene=new QGraphicsScene();

     QImage image(":/img/test/res/cosmos.jpg");
     mScene->setBackgroundBrush(QBrush(image));

     return true;

}

bool Level::createView()
{
    mCamera=new QGraphicsView();
    mCamera->setScene(mScene);

    mCamera->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mCamera->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    mCamera->setFixedSize(800,600);
    mCamera->setSceneRect(0,0,800,600);

    return true;
}

bool Level::createMediaPlayer()
{
    mediaPlayer=new QMediaPlayer();
    QMediaPlaylist* playlist=new QMediaPlaylist();

    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    playlist->addMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath()+"/res/Subjected_rancor.mp3")); //Ultraviolence - Psycho Drama - 05 - Psycho Drama.mp3 Subjected_rancor.mp3

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
    qDebug()<<"spawn start";
       QGraphicsItem* enemy=mSpawner->create();
       int randomNumber=rand() %700;
       enemy->setPos(randomNumber,0);
       mScene->addItem(enemy); qDebug()<<"add item to scene" ;
}

void Level::test1()
{

    emit(changeState(new MainMenu));
}

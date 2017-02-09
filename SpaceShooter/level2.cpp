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

Level2::Level2(int mod):AGameState("Level2")
{

        qDebug()<<"start kon level2";
        mode = mod ;
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




    qDebug()<<"kon level2";
}

void Level2::onEnter()
{
    qDebug()<<"start onEnter level2 state";


    mCamera->showNormal();
    mediaPlayer->play();

    qDebug()<<"end onEnter level2 state";

}

void Level2::onExit()
{
    mCamera->hide();


}

void Level2::play()
{
    qDebug()<<"play level2 state";

    //mCamera->show();
    mSpawnTimer->start(1000);

    qDebug()<<"end play level2 state";
}



Level2::~Level2()
{
    mScene->deleteLater();
    mCamera->deleteLater();
    mSpawner->deleteLater();
    qDebug()<<"destr level2";
}

void Level2::gameOver()
{
    //mScene->addText("GAME OVER");
    emit(changeState(new MainMenu));
}

bool Level2::createScene()
{
     mScene=new QGraphicsScene();

     QImage image(":/img/res/cosmos.jpg");
     mScene->setBackgroundBrush(QBrush(image));

     return true;

}

bool Level2::createView()
{
    mCamera=new QGraphicsView(this);
    mCamera->setScene(mScene);

    mCamera->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mCamera->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    mCamera->setFixedSize(800,600);
    mCamera->setSceneRect(0,0,800,600);

    return true;
}

bool Level2::createMediaPlayer()
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

       QGraphicsItem* enemy=mSpawner->create(mode);
       int randomNumber=rand() %650;
       enemy->setPos(randomNumber+25,0);

       mScene->addItem(enemy); qDebug()<<"add item to scene" ;
}

void Level2::test1()
{

    emit(changeState(new MainMenu));
}

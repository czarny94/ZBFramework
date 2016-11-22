#include "game.h"
#include <QTimer>
#include <QMediaPlaylist>
#include <QImage>
#include "enemy.h"

Game::Game(QWidget *parent):QGraphicsView(parent)
{
    //create s a scene
     scene=new QGraphicsScene();
    mEnemyProt=new EnemyPrototype(this);
    mSpawner=new GraphicsItemFactory(mEnemyProt,this);
    player=new Player;

    scene->addItem(player);


    QImage image(":/img/test/res/cosmos.jpg");
    score=new Score();
    scene->setBackgroundBrush(QBrush(image));
    scene->addItem(score);

    health=new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    //add a view
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    setFixedSize(800,600);
    setSceneRect(0,0,800,600);

    player->setPos(400,500);

    //spawn enemies
    QTimer* timer=new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
    timer->start(2000);

    //play bg music

    mediaPlayer=new QMediaPlayer();
    QMediaPlaylist* playlist=new QMediaPlaylist();
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    playlist->addMedia(QUrl("qrc:/sfx/res/Subjected_Rancor.mp3"));
    mediaPlayer->setPlaylist(playlist);
    mediaPlayer->volumeChanged(1);
   //mediaPlayer->play();

    //show();

}

void Game::spawn()
{   qDebug()<<"spawn start";
    QGraphicsItem* enemy=mSpawner->create();
     scene->addItem(enemy); qDebug()<<"add item to scene" ;
}

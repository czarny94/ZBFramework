#include "game.h"
#include <QTimer>
#include <QMediaPlaylist>
#include <QImage>
#include "enemy.h"

Game::Game(QWidget *parent):QGraphicsView(parent)
{
    //create s a scene
    QGraphicsScene* scene=new QGraphicsScene();

    player=new Player;
    //player->setRect(0,0,100,100);

    //make rect focusable

    Enemy* enemy=new Enemy();
    enemy->setPos(400,500);
    //add the item to the scene
    scene->addItem(player);
    scene->addItem(enemy);

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
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
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

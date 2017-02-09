#include "mainmenu.h"
#include <QDebug>



#include "SpaceShooter/level.h"
#include "SpaceShooter/level2.h"
#include <QApplication>
#include <QGraphicsLinearLayout>
#include <QTimer>
#include <QMediaPlaylist>

MainMenu::MainMenu():AGameState("MainMenu")
{
    //setBaseSize(800,600);
    mScene=new QGraphicsScene(this);

    mCamera=new QGraphicsView(mScene,this);




    qDebug()<<"konstruktor mm";
}

void MainMenu::onEnter()
{
    qDebug()<<"wchode do onEnter mm";
    mNewGame1Button=new QPushButton("Level 1");//,mCamera);
    connect(mNewGame1Button,SIGNAL(clicked(bool)),this,SLOT(newGame1()));
    mNewGame2Button=new QPushButton("Level 2");//,mCamera);
    connect(mNewGame2Button,SIGNAL(clicked(bool)),this,SLOT(newGame2()));
    mNewGame3Button=new QPushButton("Level 3");//,mCamera);
    connect(mNewGame3Button,SIGNAL(clicked(bool)),this,SLOT(newGame3()));
    mExitButton=new QPushButton("Exit");//,mCamera);
    connect(mExitButton,SIGNAL(clicked(bool)),this,SLOT(exit()));

//    mOptionsButton=new QPushButton("Options",this);
//    mCreditsButton=new QPushButton("Credits",this);
//    mLoadButtun=new QPushButton("Load Game",this);

//    mLoadButtun->setGeometry(100,0,100,100);
//    mOptionsButton->setGeometry(200,0,100,100);

//    mCreditsButton->setGeometry(300,0,100,100);


    mProxyButtons["NewGame1"]=mScene->addWidget(mNewGame1Button);
    mProxyButtons["NewGame2"]=mScene->addWidget(mNewGame2Button);
    mProxyButtons["NewGame3"]=mScene->addWidget(mNewGame3Button);
    mProxyButtons["Exit"]= mScene->addWidget(mExitButton);

    QGraphicsLinearLayout *Layout = new QGraphicsLinearLayout(
                Qt::Vertical);
    Layout->addItem(mProxyButtons["NewGame1"]);
    Layout->addItem(mProxyButtons["NewGame2"]);
    Layout->addItem(mProxyButtons["NewGame3"]);
   Layout->addItem(mProxyButtons["Exit"]);

   QGraphicsWidget *widget = new QGraphicsWidget();
       widget->setLayout(Layout);
       mScene->addItem(widget);


    mCamera->setFixedSize(800,600);
    mScene->setSceneRect(0,0,800,600);
    mCamera->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mCamera->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mScene->setBackgroundBrush(QBrush(QImage(":/img/res/spacecity.jpg")));

//    mediaPlayer=new QMediaPlayer();
//    QMediaPlaylist* playlist=new QMediaPlaylist();
//    playlist->setPlaybackMode(QMediaPlaylist::Loop);
//    playlist->addMedia();
//    mediaPlayer->setPlaylist(playlist);
//    mediaPlayer->volumeChanged(100);
//    mediaPlayer->play();

    qDebug()<<"onEnter mm";


}

void MainMenu::onExit()
{

    mCamera->hide();
    //mCamera->setScene(nullptr);
    //mScene->clear();


    qDebug()<<"on Exit mm";
}

void MainMenu::play()
{
    qDebug()<<"play mm";
    mCamera->show();
}

MainMenu::~MainMenu()
{
    mScene->clear();
    mCamera->deleteLater();
    mScene->deleteLater();

    qDebug()<<"dest mm";
}

void MainMenu::newGame1()
{
    AGameState* temp=new Level();
    emit(changeState(temp));
}

void MainMenu::newGame2()
{
    AGameState* temp=new Level2(2);
    emit(changeState(temp));    
}

void MainMenu::newGame3()
{
    AGameState* temp=new Level2(3);
    emit(changeState(temp));
}

void MainMenu::exit()
{
    QApplication::exit();
}

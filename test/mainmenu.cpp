#include "mainmenu.h"
#include <QDebug>



#include "test/level.h"
#include <QApplication>
#include <QGraphicsLinearLayout>
#include <QTimer>
#include <QMediaPlaylist>

MainMenu::MainMenu():AGameState("MainMenu")
{
    //setBaseSize(800,600);
    mScene=new QGraphicsScene(this);

    mCamera=new QGraphicsView(mScene);




    qDebug()<<"konstruktor mm";
}

void MainMenu::onEnter()
{
    qDebug()<<"wchode do onEnter mm";
    mNewGameButton=new QPushButton("New Game");//,mCamera);
    connect(mNewGameButton,SIGNAL(clicked(bool)),this,SLOT(newGame()));
    mExitButton=new QPushButton("Exit");//,mCamera);
    connect(mExitButton,SIGNAL(clicked(bool)),this,SLOT(exit()));

//    mOptionsButton=new QPushButton("Options",this);
//    mCreditsButton=new QPushButton("Credits",this);
//    mLoadButtun=new QPushButton("Load Game",this);

//    mLoadButtun->setGeometry(100,0,100,100);
//    mOptionsButton->setGeometry(200,0,100,100);

//    mCreditsButton->setGeometry(300,0,100,100);


    mProxyButtons["NewGame"]=mScene->addWidget(mNewGameButton);
    mProxyButtons["Exit"]= mScene->addWidget(mExitButton);

    QGraphicsLinearLayout *Layout = new QGraphicsLinearLayout(
                Qt::Vertical);
   Layout->addItem(mProxyButtons["NewGame"]);
   Layout->addItem(mProxyButtons["Exit"]);

   QGraphicsWidget *widget = new QGraphicsWidget();
       widget->setLayout(Layout);
       mScene->addItem(widget);


    mCamera->setFixedSize(800,600);
    mScene->setSceneRect(0,0,800,600);
    mCamera->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mCamera->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mScene->setBackgroundBrush(QBrush(QImage(":/img/test/spacecity.jpg")));

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

void MainMenu::newGame()
{
    AGameState* temp=new Level();
    emit(changeState(temp));
}

void MainMenu::exit()
{
    QApplication::exit();
}

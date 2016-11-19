#include "engine.h"
#include <QApplication>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Engine* w=new Engine(&a);
    //w->play();




/*
    QGraphicsScene* mScene=new QGraphicsScene();
    //mScene->setSceneRect(0,0,800,600);
    QGraphicsView* mCamera=new QGraphicsView(mScene);





    QPushButton* mNewGameButton=new QPushButton("New Game");
    QPushButton* mExitButton=new QPushButton("Exit");

    mNewGameButton->setGeometry(0,0,100,100);


    mExitButton->setGeometry(400,0,100,100);
    //connect(mExitButton,SIGNAL(pressed()),qApp,SLOT(exit()));
    mScene->addWidget(mNewGameButton);
    mScene->addWidget(mExitButton);
    mCamera->setScene(mScene);
    mCamera->setFixedSize(800,600);
    mScene->setSceneRect(0,0,800,600);
    mCamera->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mCamera->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mCamera->show();
*/

    return a.exec();
}

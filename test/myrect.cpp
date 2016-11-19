#include "myrect.h"
#include <QDebug>
#include "bullet.h"
#include "enemy.h"

MyRect::MyRect(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    sound=new QSound(":/music/test/res/phaser.wav");//(QUrl("qrc:/sfx/res/phaser.wav"));//QMediaPlayer();
   // sound->setMedia(QUrl("qrc:/sfx/res/phaser.wav"));
    TextureManager* texManag= TextureManager::getInstance();

    setPixmap(QPixmap(":/img/test/res/boss1.png"));
    setScale(0.5);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setTransformOriginPoint(50,50);
    setRotation(90);
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"key pressed";


   if (event->key()==Qt::Key_Right)
   {
        if(x()+100<800)
        setPos(x()+10,y());
   }
   else if(event->key()== Qt::Key_Left)
   {
       if(x()>0)
       setPos(x()-10,y());
    }
    if (event->key()==Qt::Key_Up)
        setPos(x(),y()-10);

   else if (event->key()==Qt::Key_Down)
            setPos(x(),y()+10);
    if (event->key()==Qt::Key_Space)
   {
          Bullet* bullet=new Bullet(parentItem());
          //qreal rectWidth=rect().width();
          bullet->setPos(x(),y());
          scene()->addItem(bullet);
          //if(!sound->isFinished())
          //{
          //    sound->stop();
          //}

          sound->play();

    }

}
/**Create a enemy*/
void MyRect::spawn()
{
    Enemy* enemy=new Enemy();
    scene()->addItem(enemy);
}

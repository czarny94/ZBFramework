#include "player.h"
#include <QDebug>
#include "bullet.h"
#include "enemy.h"
#include <QImage>
Player::Player(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    sound=new QSound(":/music/test/res/phaser.wav");//(QUrl("qrc:/sfx/res/phaser.wav"));//QMediaPlayer();
   // sound->setMedia(QUrl("qrc:/sfx/res/phaser.wav"));
    TextureManager* texManag= TextureManager::getInstance();
    QString error;

    try
    {
         mTexture=texManag->loadTexture("res/boss1.png");
    }
    catch(QString &error)
    {
        qDebug()<<error;
    }


    setPixmap(*mTexture);

    setScale(0.5);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setTransformOriginPoint(50,50);
    setRotation(90);
}

void Player::keyPressEvent(QKeyEvent *event)
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

Player::~Player()
{
    mTexture.reset();
    TextureManager::getInstance()->deleteTexture("player");
}
/**Create a enemy*/
void Player::spawn()
{
    Enemy* enemy=new Enemy();
    scene()->addItem(enemy);
}

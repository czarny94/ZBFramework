#include "player.h"
#include <QDebug>
#include "test/bullet.h"
#include "test/enemy.h"
#include <QImage>
#include <QRectF>
Player::Player(int health):PixmapEntity(3)
{
    sound=new QSound(":/music/test/res/phaser.wav");

    TextureManager* texManag= TextureManager::getInstance();
    QString error;

    try
    { mTextureLeft=texManag->loadTexture("res/playerLeft.png","PNG");


         mTextureRight=texManag->loadTexture("res/playerRight.png","PNG");mTexture=texManag->loadTexture("res/player.png","PNG");
    }
    catch(QString &error)
    {
        qDebug()<<error;
    }


    setPixmap(*mTexture);

    //setScale(0.5);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    //setTransformOriginPoint(center());
    //setRotation(90);


    mBasicBullet=new BulletPrototype(/*this*/);
    mPhazer=new GraphicsItemFactory(mBasicBullet/*,this*/);


    calculateCenter();
    QRectF bRect= boundingRect();
    qreal width= bRect.width();

    mTopCenter=width/2;


}

void Player::keyPressEvent(QKeyEvent *event)
{
    //qDebug()<<"key pressed";


   if (event->key()==Qt::Key_Right)
   {
        if(x()+100<800)
        setPos(x()+10,y());
        qDebug()<<"right";
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
        qDebug()<<"shoot";
        attack();

    }

}

QPointF Player::center()
{
    return mCenter;
}

void Player::attack()
{
    QGraphicsItem* bullet=mPhazer->create();

    qreal bb=bullet->boundingRect().width()/2;

    bullet->setPos(x()+mTopCenter-bb,y());

    scene()->addItem(bullet);

    sound->play();
}

Player::~Player()
{
    mTexture.reset();
    TextureManager::getInstance()->deleteTexture("player");
}

void Player::hit(int dmg)
{
    mHealth-=dmg;
    //emit(healthChanges(mHealth));
    if(mHealth <=0)
    {
       // emit(entityDead());
    }
}

int Player::getHealth()
{
    return mHealth;
}

void Player::calculateCenter()
{
     QRectF rect=boundingRect();
     mCenter=rect.center();
}


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
    {
        mTextureLeft=texManag->loadTexture("res/playerLeft.png","PNG");
         mTextureRight=texManag->loadTexture("res/playerRight.png","PNG");
         mTexture=texManag->loadTexture("res/player.png","PNG");
    }
    catch(QString &error)
    {
        qDebug()<<error;
    }

    mStateMachine=new PlayerStateMachine(this);
    setPixmap(*mTexture);

    //setScale(0.5);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    //setTransformOriginPoint(center());
    //setRotation(90);


    mBasicBullet=new BulletPrototype(/*this*/);
    mPhazer=new GraphicsItemFactory(mBasicBullet/*,this*/);
    mStateMachine->start();

    calculateCenter();
    QRectF bRect= boundingRect();
    qreal width= bRect.width();
    mTopCenter=width/2;





}

void Player::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"key pressed";


    if (event->key()==Qt::Key_Right)
    {
        mStateMachine->moveRight();
    }
    if(event->key()== Qt::Key_Left)
    {
        mStateMachine->moveLeft();
    }
    if (event->key()==Qt::Key_Up)
    {
        mStateMachine->moveUp();
    }
    if (event->key()==Qt::Key_Down)
    {
        mStateMachine->moveDown();
    }
    if (event->key()==Qt::Key_Space)
    {
        mStateMachine->shoot();
    }



//   if (event->key()==Qt::Key_Right)
//   {
//        if(x()+100<800)
//        setPos(x()+10,y());
//        qDebug()<<"right";
//        if (event->key()==Qt::Key_Space)
//       {
//            qDebug()<<"shoot";
//            attack();

//        }
//   }
//   else if(event->key()== Qt::Key_Left)
//   {
//       if(x()>0)
//       setPos(x()-10,y());
//       if (event->key()==Qt::Key_Space)
//      {
//           qDebug()<<"shoot";
//           attack();

//       }
//    }
//    if (event->key()==Qt::Key_Up)
//    {
//        setPos(x(),y()-10);
//        if (event->key()==Qt::Key_Space)
//       {
//            qDebug()<<"shoot";
//            attack();

//        }
//    }
//   else if (event->key()==Qt::Key_Down)
//    {
//            setPos(x(),y()+10);
//            if (event->key()==Qt::Key_Space)
//           {
//                qDebug()<<"shoot";
//                attack();

//            }
//    }
//    if (event->key()==Qt::Key_Space)
//   {
//        qDebug()<<"shoot";
//        attack();

//    }

}

void Player::keyReleaseEvent(QKeyEvent *event)
{

     if(event->isAutoRepeat())
         event->ignore();

    else if (event->key()==Qt::Key_Right)
    {
         qDebug()<<"key unpressed";
        mStateMachine->stopMoving();
    }
    else if(event->key()== Qt::Key_Left)
    {
         qDebug()<<"key unpressed";
        mStateMachine->stopMoving();
    }

}

QPointF Player::center()
{
    return mCenter;
}

void Player::setTexture(Player::Texture tex)
{
    switch(tex)
    {
    case(RIGHT):
        setPixmap(*mTextureRight);
        break;
    case(LEFT):
        setPixmap(*mTextureLeft);
        break;
    case(STATIC):
        setPixmap(*mTexture);
        break;
    default:
        break;
    }
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


#include "player.h"
#include <QDebug>
#include "SpaceShooter/bullet.h"
#include "SpaceShooter/enemy.h"
#include <QImage>
#include <QRectF>

Player::Player(int health):PixmapEntity(3)
{
    sound=new QSound(":/sfx/res/phaser.wav");

    SpriteManager* texManag= SpriteManager::getInstance();
    QString error;

    try
    {
        mSpriteLeft=texManag->loadSprite("res/playerLeft.png","PNG");
         mSpriteRight=texManag->loadSprite("res/playerRight.png","PNG");
         mSprite=texManag->loadSprite("res/player.png","PNG");
    }
    catch(QString &error)
    {
        qDebug()<<error;
    }

    mStateMachine=new PlayerStateMachine(this);
    setPixmap(*mSprite);

    //setScale(0.5);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    //setTransformOriginPoint(center());
    //setRotation(90);


    mBasicBullet=new BulletPrototype(/*this*/);
    mPhazer=new GraphicsItemFactory(mBasicBullet);
    mStateMachine->start();

    calculateCenter();
    QRectF bRect= boundingRect();
    qreal width= bRect.width();
    mTopCenter=width/2;


    speed = 5;




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

void Player::setTexture(Player::SPRITE tex)
{
    switch(tex)
    {
    case(RIGHT):
        setPixmap(*mSpriteRight);
        break;
    case(LEFT):
        setPixmap(*mSpriteLeft);
        break;
    case(STATIC):
        setPixmap(*mSprite);
        break;
    default:
        break;
    }
}

void Player::attack()
{
    QGraphicsItem* bullet=mPhazer->create(1);

    qreal bb=bullet->boundingRect().width()/2;

    bullet->setPos(x()+mTopCenter-bb,y());

    scene()->addItem(bullet);

    sound->play();
    /*
     * //pojawil mi sie ciekawy problem, podczas zmiany sposobu poruszania sie przeciwnikow
     * //dla tych ktorzy ruszali sie tez w poziomie odswiezanie przy wyszukiwaniu trafien
     * //nie do konca dzialalo, mozna dopisac do testowania, na ten moment jeszcze nie
     * //rozwiazane
     * rozwiązanie: zmiana w metdzie sprawdzającej kolizje czy zostały inne
     * klasy też są brane pod uwagę
     */
}

Player::~Player()
{
    mSprite.reset();
    SpriteManager::getInstance()->deleteSprite("player");
}

void Player::hit(int dmg)
{
    mHealth-=dmg;
    //emit(healthChanges(mHealth));
    if(mHealth <=0)
    {
        emit(entityDead());
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


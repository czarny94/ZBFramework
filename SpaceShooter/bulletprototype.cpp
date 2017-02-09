#include "SpaceShooter/bulletprototype.h"
#include "core/spritemanager.h"
#include <QDebug>

BulletPrototype::BulletPrototype(QObject* parent):APrototype(parent)
{

    SpriteManager* texManag= SpriteManager::getInstance();
    QString error;

    try
    {
        mSprite=texManag->loadSprite("res/bullet1.png");
    }
    catch(QString &error)
    {
        qDebug()<<error;
    }

    mSound=new QSound(":/sfx/res/boom.wav");
}

QGraphicsItem *BulletPrototype::clone()
{
    return new Bullet(mSprite.get(),mSound);
}

QGraphicsItem *BulletPrototype::clone2()
{
    return new Bullet(mSprite.get(),mSound);
}
QGraphicsItem *BulletPrototype::clone3()
{
    return new Bullet(mSprite.get(),mSound);
}

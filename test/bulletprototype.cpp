#include "test/bulletprototype.h"
#include "core/texturemanager.h"
#include <QDebug>

BulletPrototype::BulletPrototype(QObject* parent):APrototype(parent)
{

    TextureManager* texManag= TextureManager::getInstance();
    QString error;

    try
    {
        mTexture=texManag->loadTexture("res/bullet1.png");
    }
    catch(QString &error)
    {
        qDebug()<<error;
    }

    mSound=new QSound(":/music/test/res/boom.wav");
}

QGraphicsItem *BulletPrototype::clone()
{
    return new Bullet(mTexture.get(),mSound);
}

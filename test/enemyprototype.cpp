#include "enemyprototype.h"
#include "texturemanager.h"
#include <QDebug>

EnemyPrototype::EnemyPrototype(QObject *parent) : APrototype(parent)
{
    TextureManager* texManager=TextureManager::getInstance();
    mTexture =texManager->loadTexture("res/enemy3.png");
}

EnemyPrototype::~EnemyPrototype()
{
    mTexture.reset();
    TextureManager::getInstance()->deleteTexture("res/enemy3.png");
}

Enemy *EnemyPrototype::clone()
{
    qDebug()<<"clone enemy a";
    QPixmap* pix=mTexture.get();
    return new Enemy(pix);

}

#include "SpaceShooter/enemyprototype.h"
#include "core/spritemanager.h"
#include <QDebug>

EnemyPrototype::EnemyPrototype(QObject *parent) : APrototype(parent)
{
    SpriteManager* texManager=SpriteManager::getInstance();
    mSprite =texManager->loadSprite("res/enemy3.png");
}

EnemyPrototype::~EnemyPrototype()
{
    mSprite.reset();
    SpriteManager::getInstance()->deleteTexture("res/enemy3.png");
}

Enemy *EnemyPrototype::clone()
{
    qDebug()<<"clone enemy a";
    QPixmap* pix=mSprite.get();

    return new Enemy(pix,parent());

}

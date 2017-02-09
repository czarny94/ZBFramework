#include "enemyspawner.h"

EnemySpawner::EnemySpawner(APrototype *prot,QObject* parent ):GraphicsItemFactory(prot,parent)
{
    mTimer=new QTimer(this);
    connect(mTimer,SIGNAL(timeout()),this,SLOT(create()));
}

EnemySpawner::EnemySpawner(QObject *parent):GraphicsItemFactory(parent)
{

}

void EnemySpawner::startTimer(int mSec)
{
    connect(mTimer,SIGNAL(timeout()),this,SLOT(create()));
    mTimer->start(mSec);

}

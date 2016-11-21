#include "enemyprototype.h"

EnemyPrototype::EnemyPrototype(QObject *parent) : APrototype(parent)
{

}

Enemy *EnemyPrototype::clone()
{
    return new Enemy();
}

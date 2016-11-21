#ifndef ENEMYPROTOTYPE_H
#define ENEMYPROTOTYPE_H

#include <QObject>
#include <QGraphicsItem>
#include "aprototype.h"
#include "test/enemy.h"
class EnemyPrototype : public APrototype
{
    Q_OBJECT
public:
    explicit EnemyPrototype(QObject *parent = 0);

signals:

public slots:
    Enemy* clone() override;
};

#endif // ENEMYPROTOTYPE_H

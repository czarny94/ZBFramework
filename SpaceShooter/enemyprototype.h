#ifndef ENEMYPROTOTYPE_H
#define ENEMYPROTOTYPE_H

#include <QObject>
#include <QGraphicsItem>
#include <memory>
#include "core/aprototype.h"
#include "SpaceShooter/enemy.h"
#include "SpaceShooter/enemy2.h"
#include "SpaceShooter/enemy3.h"
class EnemyPrototype : public APrototype
{
    Q_OBJECT
public:
    explicit EnemyPrototype(QObject *parent = 0);
    ~EnemyPrototype();
signals:

public slots:
    Enemy* clone() override;
    Enemy2 * clone2() override ;
    Enemy3 * clone3() override ;
private:
    std::shared_ptr<QPixmap> mSprite;
};

#endif // ENEMYPROTOTYPE_H

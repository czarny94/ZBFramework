#ifndef ENEMYPROTOTYPE_H
#define ENEMYPROTOTYPE_H

#include <QObject>
#include <QGraphicsItem>
#include <memory>
#include "core/aprototype.h"
#include "test/enemy.h"
class EnemyPrototype : public APrototype
{
    Q_OBJECT
public:
    explicit EnemyPrototype(QObject *parent = 0);
    ~EnemyPrototype();
signals:

public slots:
    Enemy* clone() override;
private:
    std::shared_ptr<QPixmap> mSprite;
};

#endif // ENEMYPROTOTYPE_H

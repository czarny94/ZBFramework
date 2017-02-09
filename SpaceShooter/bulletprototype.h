#ifndef BULLETPROTOTYPE_H
#define BULLETPROTOTYPE_H

#include <QObject>
#include <memory>
#include <QSound>
#include <QGraphicsItem>

#include "core/aprototype.h"
#include "SpaceShooter/bullet.h"

class BulletPrototype : public APrototype
{
public:
    BulletPrototype(QObject* parent=nullptr);

    QGraphicsItem* clone() override;
    QGraphicsItem* clone2() override;
    QGraphicsItem* clone3() override;
private:
    std::shared_ptr<QPixmap> mSprite;
    QSound* mSound;

};

#endif // BULLETPROTOTYPE_H

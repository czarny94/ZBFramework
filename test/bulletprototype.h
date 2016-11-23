#ifndef BULLETPROTOTYPE_H
#define BULLETPROTOTYPE_H

#include <QObject>
#include <memory>
#include <QSound>
#include <QGraphicsItem>

#include "aprototype.h"
#include "test/bullet.h"

class BulletPrototype : public APrototype
{
public:
    BulletPrototype(QObject* parent=nullptr);

    QGraphicsItem* clone() override;
private:
    std::shared_ptr<QPixmap> mTexture;
    QSound* mSound;

};

#endif // BULLETPROTOTYPE_H

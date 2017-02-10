#ifndef SINCRASHER_H
#define SINCRASHER_H
#include "enemy.h"
#include <cstdlib>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QList>
#include <typeinfo>


#include <QDebug>
#include "SpaceShooter/player/player.h"
class SinCrasher : public Enemy
{
  Q_OBJECT
public:
    SinCrasher(QPixmap* texture,QObject* parent=0);
    void move() override;
    void hit(int dmg);
    ~SinCrasher();
protected:
    int xPos;
    int speed;
    int enemyType;
    bool right = true;
signals:
    void enemyKilled();
};

#endif // SINCRASHER_H

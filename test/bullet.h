#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QSound>

#include "texturemanager.h"
class Bullet:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent=0);
public slots:
    void move();
private:
    std::shared_ptr<QPixmap> texture;
    QSound* sound;


};

#endif // BULLET_H

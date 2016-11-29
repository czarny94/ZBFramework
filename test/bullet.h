#ifndef BULLET_H
#define BULLET_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QSound>
#include <QPixmap>

#include "core/texturemanager.h"
class Bullet:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent=0);
    Bullet(QPixmap* texture, QSound* sound,QGraphicsItem* parent=0 );
public slots:
    void move();
private:
    QPixmap* mTexture;
    QSound* mSound;


};

#endif // BULLET_H

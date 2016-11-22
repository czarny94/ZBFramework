#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QSound>
#include <QGraphicsPixmapItem>
#include <QPixmap>


class Enemy:public QObject,public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Enemy(QPixmap* texture);
public slots:
    void move();
    void anim();
private:
    int tick;
    QSound* sound;
    QPixmap* sheet;
    int frame;
    int width;
    qreal fWidth;


};





#endif // ENEMY_H

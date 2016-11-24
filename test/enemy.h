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
    Enemy(QPixmap* texture,QObject* parent=0);
    ~Enemy();
public slots:
    virtual void move();
    virtual void anim();
    virtual void hit(int dmg);
    virtual void attack();
protected:
    int frame;
    int width;
    int tick;
    QSound* mSound;
    QPixmap* sheet;

    qreal fWidth;

    int mHealth;
signals:
    void shootDown();

};





#endif // ENEMY_H

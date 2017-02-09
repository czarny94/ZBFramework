#ifndef ENEMY3_H
#define ENEMY3_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QSound>
#include <QGraphicsPixmapItem>
#include <QPixmap>


class Enemy3:public QObject,public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Enemy3(QPixmap* texture,QObject* parent=0);
    ~Enemy3();
public slots:
    virtual void move();
    virtual void anim();
    virtual void hit(int dmg);
    virtual void attack();
protected:
    int frame;
    int width;
    int tick;
    int heading ;
    int movingleft ;
    QSound* mSound;
    QPixmap* mSprite;

    qreal fWidth;

    int mHealth;
signals:
    void shootDown();

};



#endif // ENEMY3_H

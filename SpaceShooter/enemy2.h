#ifndef ENEMY2_H
#define ENEMY2_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QSound>
#include <QGraphicsPixmapItem>
#include <QPixmap>


class Enemy2:public QObject,public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Enemy2(QPixmap* texture,QObject* parent=0);
    ~Enemy2();
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
    QPixmap* mSprite;

    qreal fWidth;
    bool heading ; // definiuje w ktorym kierunku sie porusza przeciwnik
    int mHealth;
signals:
    void shootDown();

};



#endif // ENEMY2_H

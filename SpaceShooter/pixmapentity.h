#ifndef PIXMAPENTITY_H
#define PIXMAPENTITY_H

#include <QObject>
#include <QGraphicsPixmapItem>

class PixmapEntity : public QGraphicsPixmapItem //moze bedzie dziedziczyc tylko po QObject, kolejne klasy beda dziedziczyly po roznych QGraphicsItem
{
    //Q_OBJECT
public:
    PixmapEntity();
    PixmapEntity(int health=1);

    //virtual QPointF center()=0;
public ://slots:
    virtual void hit(int dmg=1)=0;
    
    virtual void attack()=0;


protected:
    int mHealth;
//signals:
//    void entityDead();
//    void healthChanges(int);

};

#endif // PIXMAPENTITY_H

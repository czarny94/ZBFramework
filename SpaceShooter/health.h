#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>


class Health : public QGraphicsTextItem
{
    Q_OBJECT
public:
    Health(QGraphicsItem* parent=0);
    int getHealth();
public slots:
     void set(int h);
private:
    int health;

};

#endif // HEALTH_H

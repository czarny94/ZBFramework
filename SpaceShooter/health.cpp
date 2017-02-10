#include "health.h"
#include <QFont>

#include <QDebug>

Health::Health(QGraphicsItem* parent):QGraphicsTextItem(parent),health(3)
{
    setPlainText(QString("Health: ")+QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont(QString("Times"),16));
}

int Health::getHealth()
{
    return health;

}

void Health::set(int h)
{
    health=h;
    setPlainText(QString("Health: ")+QString::number(health));

    qDebug()<<"health--";
}


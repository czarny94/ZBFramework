#include "health.h"
#include <QFont>

Health::Health():health(3)
{
    setPlainText(QString("Health: ")+QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont(QString("Times"),16));
}

int Health::getHealth()
{
    return health;

}

void Health::decrease(int h)
{

    setPlainText(QString("health: ")+QString::number(h));
}

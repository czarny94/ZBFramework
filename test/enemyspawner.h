#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include <QObject>
#include <QTimer>

#include "graphicsitemfactory.h"

class EnemySpawner : public GraphicsItemFactory
{
public:
    EnemySpawner(APrototype *prot=nullptr,QObject* parent=nullptr );
    EnemySpawner(QObject* parent =nullptr);
public slots:
    void startTimer(int interval);
private:
    QTimer* mTimer;
};

#endif // ENEMYSPAWNER_H

#ifndef GAMEGUI_H
#define GAMEGUI_H

#include <QObject>
#include <QGraphicsObject>
#include "SpaceShooter/health.h"
#include "SpaceShooter/score.h"

class GameGUI :public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
 GameGUI(QObject *parent = 0);

signals:

public slots:
    void changeHealth(int h);
    void changeScore(int s);
private:
    Score* mScore;
    Health* mHealth;
 };

#endif // GAMEGUI_H

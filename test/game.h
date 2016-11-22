#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QMediaPlayer>
#include "player.h"
#include "score.h"
#include "health.h"
#include "graphicsitemfactory.h"
#include "test/enemyprototype.h"


class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget* parent=0);
    Score* score;
    Health* health;
private:
    QGraphicsScene* scene;
    Player * player;
    QMediaPlayer * mediaPlayer;
    EnemyPrototype* mEnemyProt;
    GraphicsItemFactory* mSpawner;

public slots:
    void spawn();

};

#endif // GAME_H

#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QMediaPlayer>
#include "player.h"
#include "score.h"
#include "health.h"


class Game : public QGraphicsView
{
public:
    Game(QWidget* parent=0);
    Score* score;
    Health* health;
private:
    QGraphicsScene* scene;
    Player * player;
    QMediaPlayer * mediaPlayer;

};

#endif // GAME_H

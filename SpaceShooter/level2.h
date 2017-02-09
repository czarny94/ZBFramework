#ifndef LEVEL2_H
#define LEVEL2_H
#include "core/agamestate.h"
#include "SpaceShooter/player/player.h"
#include "SpaceShooter/score.h"
#include "SpaceShooter/health.h"

#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QKeyEvent>

#include "SpaceShooter/enemyspawner.h"
#include "SpaceShooter/enemyprototype.h"
#include "SpaceShooter/gamegui.h"
#include "SpaceShooter/level.h"



class Level2 : public Level
{
    Q_OBJECT
public:
    Level2(int mod);


public slots:
    void gameOver();
private:

   int mode ;

   bool createSpawner();
  // bool spawnBoss();
private slots:
 //  void spawnEnemy();
   void spawnEnemy2();

    void test1();
};

#endif // LEVEL2_H

#ifndef LEVEL_H
#define LEVEL_H
#include "agamestate.h"
#include "player.h"
#include "score.h"
#include "health.h"

#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QKeyEvent>

#include "test/enemyspawner.h"
#include "test/enemyprototype.h"

class Level:public AGameState
{
    Q_OBJECT
public:
    Level();
    void onEnter() override;
    void onExit() override;
    void play() override;


    Score* score;
    Health* health;

    ~Level();
private:
   QGraphicsView* mCamera;
   QGraphicsScene* mScene;

   GraphicsItemFactory* mSpawner;
   Player* mPlayer;

   QMediaPlayer* mediaPlayer;

   QTimer* mSpawnTimer;

   bool createScene();
   bool createView();
   bool createMediaPlayer();
   bool createSpawner();
private slots:
   void spawnEnemy();

    void test1();

};

#endif // LEVEL_H

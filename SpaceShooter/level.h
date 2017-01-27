#ifndef LEVEL_H
#define LEVEL_H
#include "core/agamestate.h"
#include "test/player/player.h"
#include "test/score.h"
#include "test/health.h"

#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QKeyEvent>

#include "test/enemyspawner.h"
#include "test/enemyprototype.h"
#include "test/gamegui.h"


class Level:public AGameState
{
    Q_OBJECT
public:
    Level();
    void onEnter() override;
    void onExit() override;
    void play() override;



    ~Level();
public slots:
    void gameOver();
private:
   QGraphicsView* mCamera;
   QGraphicsScene* mScene;

   Score* mScore;
   Health* mHealth;

   //GameGUI* mGui;

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

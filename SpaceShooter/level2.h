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



class Level2 : public AGameState
{
    Q_OBJECT
public:
    Level2(int mod);
    void onEnter() override;
    void onExit() override;
    void play() override;



    ~Level2();
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
   QGraphicsItem * boss ;
   QTimer* mSpawnTimer;
   int mode ;
   bool createScene();
   bool createView();
   bool createMediaPlayer();
   bool createSpawner();
  // bool spawnBoss();
private slots:
 //  void spawnEnemy();
   void spawnEnemy2();

    void test1();
};

#endif // LEVEL2_H

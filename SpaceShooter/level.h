#ifndef LEVEL_H
#define LEVEL_H
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


class Level:public AGameState
{
    Q_OBJECT
public:
    Level();
    virtual void onEnter() override;
    virtual void onExit() override;
    virtual void play() override;



    virtual ~Level();
public slots:
    void gameOver();
protected:
   QGraphicsView* mCamera;
   QGraphicsScene* mScene;

   Score* mScore;
   Health* mHealth;

   //GameGUI* mGui;

   GraphicsItemFactory* mSpawner;
   Player* mPlayer;

   QMediaPlayer* mediaPlayer;

   QTimer* mSpawnTimer;

   virtual bool createScene();
   virtual bool createView();
   virtual bool createMediaPlayer();
   virtual bool createSpawner();
protected slots:
   virtual void spawnEnemy();

   virtual void test1();

};

#endif // LEVEL_H

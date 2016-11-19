#ifndef LEVEL_H
#define LEVEL_H
#include "agamestate.h"

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "test/game.h"

class Level:public AGameState
{
    Q_OBJECT
public:
    Level();
    void onEnter() override;
    void onExit() override;
    void play() override;

    ~Level();
private:
   Game* mCamera;
private slots:
    void test1();

};

#endif // LEVEL_H

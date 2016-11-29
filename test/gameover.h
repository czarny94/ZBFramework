#ifndef GAMEOVER_H
#define GAMEOVER_H

//#include <QObject>
#include "core/agamestate.h"

class GameOver : public AGameState
{
    Q_OBJECT
public:
    GameOver();
    void onEnter() override;
    void onExit() override;
    void play() override;
private slots:
    void toMain();

};

#endif // GAMEOVER_H

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QObject>
#include <vector>
#include "agamestate.h"

class GameStateManager : public QObject
{
    Q_OBJECT
public:
    explicit GameStateManager(QObject *parent = 0);

    AGameState *getState();
    ~GameStateManager();

signals:
    AGameState* stateChanged(AGameState*);

public slots:
    void pushState(AGameState* state);
    void popState();
    void changeState(AGameState* state);
private slots:

protected:
    std::vector<AGameState*> mStates;
    void connectSlots(AGameState*);
};

#endif // SCENEMANAGER_H

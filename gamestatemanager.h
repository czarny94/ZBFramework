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
    void pushState(AGameState* state);
    void popState();
    void changeState(AGameState* state);
    AGameState* getScene();
    ~GameStateManager();

signals:

public slots:
protected:
    std::vector<AGameState*> mStates;

};

#endif // SCENEMANAGER_H

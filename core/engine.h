#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QGraphicsView>
#include "core/gamestatemanager.h"
#include <QMainWindow>


class Engine : public QObject
{
    Q_OBJECT

public:
    Engine(QObject *parent = 0);
    virtual ~Engine();

public slots:
    void play();
    void setCurrentState(AGameState* state);

protected:
    GameStateManager* mStateManager;
    AGameState* mCurrentState;
    QMainWindow* mainWindow;
};

#endif // ENGINE_H

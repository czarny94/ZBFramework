#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QgraphicsView>
#include "core/gamestatemanager.h"


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
    QGraphicsView* mView;


};

#endif // ENGINE_H

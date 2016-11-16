#ifndef ENGINE_H
#define ENGINE_H

#include <QWidget>
#include "gamestatemanager.h"


class Engine : public QWidget
{
    Q_OBJECT

public:
    Engine(QWidget *parent = 0);
    ~Engine();
protected:
    GameStateManager* mStateManager;


};

#endif // ENGINE_H

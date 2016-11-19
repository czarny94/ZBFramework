#ifndef AGAMESTATE_H
#define AGAMESTATE_H
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
//#include "engine.h"

//class Engine;
class AGameState : public QWidget
{
    Q_OBJECT
public:
    explicit AGameState(QString stateID);//,Engine* engine);

    virtual void onEnter()=0;
    virtual void onExit()=0;
    virtual void play()=0;
    QString getStateId(){return mStateID;}

    virtual ~AGameState();
protected:
    QGraphicsView* mCamera;
    QString mStateID;
    QGraphicsScene* mScene;
    //Engine* mEngine;
signals:
   AGameState* changeState(AGameState*);
   AGameState* pushState(AGameState*);

//moze doda sie jakies sygnaly
};

#endif // AGAMESTATE_H

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
    /**Funkcja wywoływana na wejściu stanu*/
    virtual void onEnter()=0;

    /**Funkcja wywoływana na wyjsciu stanu*/
    virtual void onExit()=0;

    /**Puszczenie stanu w ruch*/
    virtual void play()=0;

    QString getStateId(){return mStateID;}
    QGraphicsView* getView(){return mCamera;}
    //void setView(QGraphicsView* view)=0;
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

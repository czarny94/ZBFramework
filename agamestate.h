#ifndef AGAMESTATE_H
#define AGAMESTATE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>

class AGameState : public QObject
{
    Q_OBJECT
public:
    explicit AGameState(QString stateID);

    virtual void onEnter()=0;
    virtual void onExit()=0;
    QString getStateId(){return mStateID;}
    virtual ~AGameState();
protected:
    //QGraphicsView* camera;
    QString mStateID;
    QGraphicsScene* mScene;
signals:
//moze doda sie jakies sygnaly
};

#endif // AGAMESTATE_H

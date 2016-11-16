#ifndef ASCENE_H
#define ASCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>

class AScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit AScene(QObject *parent = Q_NULLPTR);
    //AScene(QString& sceneID, QObject *parent = Q_NULLPTR);
    virtual void onEnter()=0;
    virtual void onExit()=0;
    QString getSceneId(){return mSceneId;}
    virtual ~AScene();
protected:
    QGraphicsView* camera;
    QString mSceneID;
signals:
//moze doda sie jakies sygnaly
};

#endif // ASCENE_H

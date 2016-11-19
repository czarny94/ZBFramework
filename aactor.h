#ifndef AACTOR_H
#define AACTOR_H

#include <QObject>
#include <QGraphicsItem>

class AActor : public QObject
{
    Q_OBJECT
public:
    explicit AActor(QObject *parent = 0);
    virtual void setPos(qreal x, qreal y)=0;
    virtual qreal x()=0;
    virtual qreal y()=0;
    virtual QGraphicsItem* getGraphicItem(){return mGraphic;}//TODO:
   // virtual void update()=0;
    virtual ~AActor();
signals:

public slots:
protected:
    qreal mX;
    qreal mY;
    QGraphicsItem* mGraphic; //TODO: shared_ptr?
};

#endif // AACTOR_H

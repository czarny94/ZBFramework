#ifndef GRAPHICSITEMFACTORY_H
#define GRAPHICSITEMFACTORY_H

#include <QObject>
#include <QGraphicsItem>
#include "core/aprototype.h"
#include <QDebug>

/*
*template abstract factory
* base class that will be returned
prototype can returned subclass with clone()
*/

class GraphicsItemFactory:public QObject
{
Q_OBJECT
public:

    GraphicsItemFactory(APrototype* prot,QObject* parent=0);
    GraphicsItemFactory(QObject* parent=nullptr);
    virtual void setPrototype(APrototype* prot);
    virtual ~GraphicsItemFactory();

public slots:

    virtual QGraphicsItem* create(int mode);
protected:
    APrototype* mPrototype;
};

#endif // GRAPHICSITEMFACTORY_H

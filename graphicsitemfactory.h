#ifndef GRAPHICSITEMFACTORY_H
#define GRAPHICSITEMFACTORY_H

#include <QObject>
#include <QGraphicsItem>
#include "aprototype.h"

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
    virtual void setPrototype(APrototype* prot);
    virtual ~GraphicsItemFactory();


    virtual QGraphicsItem* create(){return mPrototype->clone();}
protected:
    APrototype* mPrototype;
};

#endif // GRAPHICSITEMFACTORY_H

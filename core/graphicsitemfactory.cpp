#include "graphicsitemfactory.h"

GraphicsItemFactory::GraphicsItemFactory(APrototype *prot,QObject* parent ):QObject(parent),mPrototype(prot)
{

}

GraphicsItemFactory::GraphicsItemFactory(QObject *parent):QObject(parent)
{

}


void GraphicsItemFactory::setPrototype(APrototype *prot)
{
    mPrototype=prot;
}

GraphicsItemFactory::~GraphicsItemFactory()
{
    qDebug()<<"destr factory";
}

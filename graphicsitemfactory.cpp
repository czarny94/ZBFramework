#include "graphicsitemfactory.h"

GraphicsItemFactory::GraphicsItemFactory(APrototype *prot,QObject* parent ):QObject(parent),mPrototype(prot)
{

}


void GraphicsItemFactory::setPrototype(APrototype *prot)
{
    mPrototype=prot;
}

GraphicsItemFactory::~GraphicsItemFactory()
{

}

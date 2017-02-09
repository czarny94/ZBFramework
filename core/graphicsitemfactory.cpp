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

QGraphicsItem *GraphicsItemFactory::create(int mode)
{
    switch(mode)
    {
    case 1 :
        qDebug()<<"createGItem" ;
        return mPrototype->clone() ;
    case 2 :
        qDebug()<<"createGitem2" ;
        return mPrototype->clone2();
    case 3 :
        qDebug()<<"createGitem2" ;
        return mPrototype->clone3();

    }
}

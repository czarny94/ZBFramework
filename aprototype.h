#ifndef APROTOTYPE_H
#define APROTOTYPE_H

#include <QObject>
#include <QGraphicsItem>

class APrototype:public QObject
 {Q_OBJECT
public:
    APrototype(QObject* parent=0);
public slots:
    virtual QGraphicsItem* clone()=0 ;
};

#endif // APROTOTYPE_H

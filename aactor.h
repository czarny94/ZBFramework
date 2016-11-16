#ifndef AACTOR_H
#define AACTOR_H

#include <QObject>

class AActor : public QObject
{
    Q_OBJECT
public:
    explicit AActor(QObject *parent = 0);

signals:

public slots:
};

#endif // AACTOR_H
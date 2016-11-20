#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <QObject>

class ResourceManager : public QObject
{
    Q_OBJECT
public:
    explicit ResourceManager(QObject *parent = 0);

signals:

public slots:
};

#endif // RESOURCEMANAGER_H
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QObject>

class SceneManager : public QObject
{
    Q_OBJECT
public:
    explicit SceneManager(QObject *parent = 0);

signals:

public slots:
};

#endif // SCENEMANAGER_H
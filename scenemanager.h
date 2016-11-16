#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QObject>
#include <vector>
#include "ascene.h"

class SceneManager : public QObject
{
    Q_OBJECT
public:
    explicit SceneManager(QObject *parent = 0);
    void pushScene(AScene* scene);
    void popScene(AScene* scene);
    void changeScene(AScene* scene);
    AScene* getScene();
    ~SceneManager();

signals:

public slots:
protected:
    std::vector<AScene*> mScenes;

};

#endif // SCENEMANAGER_H

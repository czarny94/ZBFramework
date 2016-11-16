#include "scenemanager.h"

SceneManager::SceneManager(QObject *parent) : QObject(parent)
{

}

void SceneManager::pushScene(AScene *scene)
{
    mScenes.push_back(scene);
    mScenes.back()->onEnter();
}

void SceneManager::popScene(AScene *scene)
{
    if (!Scenes.empty())
    {
        mScenes.back()->onExit();
        mScenes.pop_back();

    }
}

void SceneManager::changeScene(AScene *scene)
{
    if (!mScenes.empty())
    {
        if (mScenes.back()->getSceneId() == scene->getSceneId())
        {
            return;
        }
        else
        {
            mScenes.back()->onExit();
            delete mGameScenes.back();
            mScenes.pop_back();
        }
    }
    pushScene(scene);
}


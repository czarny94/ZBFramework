#include "gamegui.h"

GameGUI::GameGUI(QObject *parent) : QObject(parent)
{
    mScore=new Score();
    mScore->setPos(x(),y());

    mHealth=new Health();
    mHealth->setPos(mHealth->x(),mHealth->y()+25);

}

void GameGUI::changeHealth(int h)
{
    mHealth->set(h);
}

void GameGUI::changeScore(int s)
{
    mScore->set(s);
}

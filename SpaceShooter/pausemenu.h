#ifndef PAUSEMENU_H
#define PAUSEMENU_H
#include "core/agamestate.h"
#include <QPushButton>
#include <QHash>
#include <QString>
#include <QGraphicsProxyWidget>

class PauseMenu : public AGameState
{
public:
    PauseMenu();
    void onEnter() override;
    void onExit() override;
    void play() override;
    ~PauseMenu() override;
private:
    QPushButton* mNewGameButton;
    QPushButton* mExitButton;
     QHash<QString, QGraphicsProxyWidget*> mProxyButtons;
};

#endif // PAUSEMENU_H

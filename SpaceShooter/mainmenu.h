#ifndef MAINMENU_H
#define MAINMENU_H
#include "core/agamestate.h"
#include <QPushButton>
#include <QHash>
#include <QString>
#include <QGraphicsProxyWidget>
#include <QMediaPlayer>


class MainMenu : public AGameState
{
    Q_OBJECT
public:
    MainMenu();

    void onEnter();
    void onExit();
    void play() override;
    ~MainMenu() override;
private:
    QPushButton* mNewGameButton;
    QPushButton* mExitButton;
    //QPushButton* mOptionsButton;
   // QPushButton* mLoadButtun;
   // QPushButton* mCreditsButton;
    QHash<QString, QGraphicsProxyWidget*> mProxyButtons;

    //QMediaPlayer* mediaPlayer;
private slots:
    void newGame();
    void exit();


};

#endif // MAINMENU_H

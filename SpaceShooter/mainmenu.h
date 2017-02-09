#ifndef MAINMENU_H
#define MAINMENU_H
#include "core/agamestate.h"
#include <QPushButton>
#include <QHash>
#include <QString>
#include <QGraphicsProxyWidget>
#include <QMediaPlayer>
#include <QGraphicsLinearLayout>

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
    QPushButton* mNewGame1Button;
    QPushButton* mNewGame2Button;
    QPushButton* mNewGame3Button;
    QPushButton* mExitButton;
    //QPushButton* mOptionsButton;
   // QPushButton* mLoadButtun;
   // QPushButton* mCreditsButton;
    QHash<QString, QGraphicsProxyWidget*> mProxyButtons;
    QGraphicsLinearLayout *Layout;
    QGraphicsWidget *widget;
    //QMediaPlayer* mediaPlayer;
private slots:
    void newGame1();
    void newGame2();
    void newGame3();
    void exit();


};

#endif // MAINMENU_H

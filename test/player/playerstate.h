#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

#include <QState>
#include <QTimer>


class Player;
class PlayerState : public QState
{
    Q_OBJECT
public:
    PlayerState(Player* player, QState *parent = nullptr);
public slots:
    virtual void moveLeft()=0;
    virtual void moveRight()=0;
    virtual void moveUp();
    virtual void moveDown();
    virtual void shoot();
    virtual void stopMoving();


protected slots:
    virtual void setTexture()=0;


protected:
    Player* mPlayer;
    QTimer* mTimer;
signals:
    void left();
    void right();
    void stop();

};

#endif // PLAYERSTATE_H

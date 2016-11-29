#ifndef MOVEDRIGHT_H
#define MOVEDRIGHT_H
#include "test/player/playerstate.h"

class MovedRight : public PlayerState
{
    Q_OBJECT
public:
    MovedRight(Player* player, QState *parent =nullptr);

public slots:
    virtual void moveLeft();
    virtual void moveRight();
    void move();

protected slots:
    void setTexture() ;
private:
    QTimer* mTimer;

};
#endif // MOVEDRIGHT_H

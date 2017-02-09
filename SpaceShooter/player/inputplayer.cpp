#include "inputplayer.h"

InputPlayer::InputPlayer(QObject *parent) : QObject(parent)
{

}

void InputPlayer::keyPressEvent(QKeyEvent *event)
{
    if (event->key()==Qt::Key_Right)
    {
        emit(moveRight());
    }
    if(event->key()== Qt::Key_Left)
    {
        emit(moveLeft());
    }
    if (event->key()==Qt::Key_Up)
    {
        emit(moveUp());
    }
    if (event->key()==Qt::Key_Down)
    {
        emit(moveDown());
    }
    if (event->key()==Qt::Key_Space)
    {
        emit(shoot());

    }
}

void InputPlayer::keyRealaseEvent(QKeyEvent *event)
{
    if (event->key()==Qt::Key_Right)
    {
        emit(stopMoving());
    }
    if(event->key()== Qt::Key_Left)
    {
        emit(stopMoving());
    }
    if (event->key()==Qt::Key_Up)
    {
        emit(stopMoving());
    }
    if (event->key()==Qt::Key_Down)
    {
       emit(stopMoving());
    }
}

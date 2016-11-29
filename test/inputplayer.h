#ifndef INPUTPLAYER_H
#define INPUTPLAYER_H

#include <QObject>
#include <QKeyEvent>

class InputPlayer : public QObject
{
    Q_OBJECT
public:
    explicit InputPlayer(QObject *parent = 0);
    void keyPressEvent(QKeyEvent* event);
    void keyRealaseEvent(QKeyEvent* event);

signals:
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void stopMoving();
    void shoot();
public slots:
};

#endif // INPUTPLAYER_H

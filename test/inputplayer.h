#ifndef INPUTPLAYER_H
#define INPUTPLAYER_H

#include <QObject>

class InputPlayer : public QObject
{
    Q_OBJECT
public:
    explicit InputPlayer(QObject *parent = 0);

signals:

public slots:
};

#endif // INPUTPLAYER_H
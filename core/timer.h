#ifndef TIMER_H
#define TIMER_H
#include <QTimer>


class Timer : public QTimer
{
public:
    Timer();
    void pause();
    void resume();
protected:
    int remain;
};

#endif // TIMER_H

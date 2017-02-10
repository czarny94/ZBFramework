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
public slots:
    void restart(){
        this->start();
    }
};
#endif // TIMER_H

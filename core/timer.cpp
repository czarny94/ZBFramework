#include "timer.h"

Timer::Timer()
{

}
void Timer::pause(){
    remain = remainingTime();
    this->stop();
    //this->setInterval(remain);
}
void Timer::resume(){

    this->start();
}

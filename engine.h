#ifndef ENGINE_H
#define ENGINE_H

#include <QWidget>

class Engine : public QWidget
{
    Q_OBJECT

public:
    Engine(QWidget *parent = 0);
    ~Engine();
};

#endif // ENGINE_H

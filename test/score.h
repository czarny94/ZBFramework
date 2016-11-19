#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
public:
    Score( QWidget*  parent=0);

    int getScore();
public slots:
     void increase();
private:
    int score;
    QWidget* widget;
};

#endif // SCORE_H

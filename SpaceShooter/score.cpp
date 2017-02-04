#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem* parent):QGraphicsTextItem(parent),score(0)
{
    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::cyan);
    setFont(QFont(QString("Times"),16));
}

void Score::set(int s)
{
    score=s;
    setPlainText(QString("Score: ")+QString::number(score));
}

int Score::getScore()
{
    return score;
}

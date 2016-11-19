#include "score.h"
#include <QFont>

Score::Score(QWidget *  parent):widget(parent),score(0)
{
    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::cyan);
    setFont(QFont(QString("Times"),16));
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ")+QString::number(score));
}

int Score::getScore()
{
    return score;
}

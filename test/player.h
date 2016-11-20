#ifndef MYRECT_H
#define MYRECT_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QSound>
#include <memory>
#include "texturemanager.h"
#include "score.h"


class MyRect : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    MyRect(QGraphicsItem* parent=0);
    void keyPressEvent(QKeyEvent* event);

public slots:
    void spawn();
private:
    //QMediaPlayer* sound;
    QSound* sound;
    std::shared_ptr<QPixmap> mTexture;
};

#endif // MYRECT_H

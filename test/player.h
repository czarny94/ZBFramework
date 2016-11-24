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
#include "graphicsitemfactory.h"
#include "test/bulletprototype.h"
#include "graphicsitemfactory.h"




class Player : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem* parent=0);
    void keyPressEvent(QKeyEvent* event);
    void shoot();
    ~Player();

public slots:
    void hit(int dmg=1);
signals:
    void playerDead();
    int healthChanges(int);

private:


    QSound* sound;
    std::shared_ptr<QPixmap> mTexture;
    std::shared_ptr<QPixmap> mTextureLeft;
    std::shared_ptr<QPixmap> mTextureRight;

    qreal mTopCenter;

    GraphicsItemFactory* mPhazer;
    BulletPrototype* mBasicBullet;

    int mLives;

};

#endif // MYRECT_H

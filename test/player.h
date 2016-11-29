#ifndef MYRECT_H
#define MYRECT_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QSound>
#include <memory>

#include "core/texturemanager.h"
#include "core/graphicsitemfactory.h"
#include "test/bulletprototype.h"
#include "core/graphicsitemfactory.h"
#include "test/pixmapentity.h"




class Player : public PixmapEntity
{
   // Q_OBJECT
    friend class PlayerState;
public:
    Player(int health=3);
    void keyPressEvent(QKeyEvent* event);
    inline QPointF center();

    ~Player();

public:// slots:
    void hit(int dmg=1);
    int getHealth();
    void attack();
//signals:


private:
    QPointF mCenter;


    QSound* sound;
    std::shared_ptr<QPixmap> mTexture;
    std::shared_ptr<QPixmap> mTextureLeft;
    std::shared_ptr<QPixmap> mTextureRight;

    qreal mTopCenter;

    GraphicsItemFactory* mPhazer;
    BulletPrototype* mBasicBullet;

    void calculateCenter();



};

#endif // MYRECT_H

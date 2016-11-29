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
#include "test/player/playerstatemachine.h"

class Player : public PixmapEntity
{
   // Q_OBJECT


public:
    enum Texture{
        STATIC,
        LEFT,
        RIGHT
    };
    Player(int health=3);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    inline QPointF center();
    void setTexture(Texture tex);

    ~Player();

public:// slots:
    void hit(int dmg=1);
    int getHealth();
    void attack();
//signals:


protected:
    QPointF mCenter;


    QSound* sound;
    std::shared_ptr<QPixmap> mTexture;
    std::shared_ptr<QPixmap> mTextureLeft;
    std::shared_ptr<QPixmap> mTextureRight;

    qreal mTopCenter;

    GraphicsItemFactory* mPhazer;
    BulletPrototype* mBasicBullet;

    PlayerStateMachine* mStateMachine;
    void calculateCenter();



};

#endif // MYRECT_H

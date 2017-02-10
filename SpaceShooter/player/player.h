#ifndef MYRECT_H
#define MYRECT_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QSound>
#include <memory>

#include "core/spritemanager.h"
#include "core/graphicsitemfactory.h"
#include "SpaceShooter/bulletprototype.h"
#include "core/graphicsitemfactory.h"
#include "SpaceShooter/pixmapentity.h"
#include "SpaceShooter/player/playerstatemachine.h"

class Player :public QObject, public PixmapEntity
{
    Q_OBJECT
public:
    enum SPRITE{
        STATIC,
        LEFT,
        RIGHT
    };
    Player(int health=3);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    inline QPointF center();
    void setTexture(SPRITE sprite);
    int speed;
    ~Player();

public slots:
    void hit(int dmg=1);
    int getHealth();
    void attack();

signals:
   void entityDead();


//signals:


protected:
    QPointF mCenter;


    QSound* sound;
    std::shared_ptr<QPixmap> mSprite;
    std::shared_ptr<QPixmap> mSpriteLeft;
    std::shared_ptr<QPixmap> mSpriteRight;

    qreal mTopCenter;

    GraphicsItemFactory* mPhazer;
    BulletPrototype* mBasicBullet;

    PlayerStateMachine* mStateMachine;
    void calculateCenter();



};

#endif // MYRECT_H

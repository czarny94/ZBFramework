#ifndef BOSS1_H
#define BOSS1_H


#include <QGraphicsRectItem>
#include <QObject>
#include <QSound>
#include <QGraphicsPixmapItem>
#include <QPixmap>
/*
 * To jest klasa bossa, który podczas ruszania się co jakiś czas spawnuje dodatkowego przeciwnika
 * jednego z tych bazowych
 * natomiast, żeby działał, najpierw trzeba dodać go gdzieś wyżej, czego niestety po wielu próbach nie ogarniam
 * dlatego, zamiast to robić jest tutaj szablon
 * trzeba dodać do niego spawny (po prostu nie wiem jak się umieszcza obiekty Enemy na scenie)
 * oraz samego bossa w osobnej planszy umieścić na scenie, oczywiście jeszcze dodać grafiki
 */
class Boss1:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Boss1(QPixmap* texture,QGraphicsItem *parent =0);
    Boss1(QPixmap* sprite, QSound* sound,QGraphicsItem* parent=0 );
    void takedamage(int damage=1) ;
public slots:
    void move() ;
    void spawn() ;
    void anim() ;
private:
    int frame;
    int width;
    int tick;
    QPixmap* mSprite;
    QSound* mSound;
    qreal fWidth ;
    int hp ;
    int heading ;
    bool toleft ;
};

#endif // BOSS1_H

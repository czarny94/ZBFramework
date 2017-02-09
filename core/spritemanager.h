#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include <QObject>
#include <QPixmap>
#include <map>
#include <string>
#include <memory>

/**TextureManager zarządza texturami(QPixmap)
 *posiada mape z wskaznikami wspoldzielonymi i kluczem QString
*/
class SpriteManager : public QObject
{
    Q_OBJECT
public:
  /**Zwraca wskaznik na statyczna instancje*/
  static SpriteManager* getInstance();
  /**Wczytaj texture, rzuca wyjatki QString
    *fileName sciezka do pliku
    *id klucz do mapy
    *format
    *flags */
  std::shared_ptr<QPixmap> getSprite(QString id);
  std::shared_ptr<QPixmap> loadSprite(QString fileName,const char *format = Q_NULLPTR, Qt::ImageConversionFlags flags = Qt::AutoColor);
  /**przenosi texture utworzona poza menagerem, rzuca wyjatki QString*/
 // bool insertTexture(QPixmap* texture, QString id);
  /**Usuwa pojedyncza texture jesli nie istnieja inne referencje poza ta z mapy*/
  //replaceTexture();
  void deleteTexture(QString id);
  /**Czysci cala mape*/
  void deleteAll();
  ~SpriteManager();
signals:

public slots:
protected:
    std::map<QString,std::shared_ptr<QPixmap>> mSpritess;

private:
    SpriteManager();
    static SpriteManager* mInstance;
};

#endif // SPRITEMANAGER_H

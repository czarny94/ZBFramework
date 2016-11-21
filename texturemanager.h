#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <QObject>
#include <QPixmap>
#include <map>
#include <string>
#include <memory>

/**TextureManager zarządza texturami(QPixmap)
 *posiada mape z wskaznikami wspoldzielonymi i kluczem QString
*/
class TextureManager : public QObject
{
    Q_OBJECT
public:
  /**Zwraca wskaznik na statyczna instancje*/
  static TextureManager* getInstance();
  /**Wczytaj texture, rzuca wyjatki QString
    *fileName sciezka do pliku
    *id klucz do mapy
    *format
    *flags */
  std::shared_ptr<QPixmap> getTexture(QString id);
  std::shared_ptr<QPixmap> loadTexture(QString fileName,const char *format = Q_NULLPTR, Qt::ImageConversionFlags flags = Qt::AutoColor);
  /**przenosi texture utworzona poza menagerem, rzuca wyjatki QString*/
 // bool insertTexture(QPixmap* texture, QString id);
  /**Usuwa pojedyncza texture jesli nie istnieja inne referencje poza ta z mapy*/
  //replaceTexture();
  void deleteTexture(QString id);
  /**Czysci cala mape*/
  void deleteAll();
  ~TextureManager();
signals:

public slots:
protected:
    std::map<QString,std::shared_ptr<QPixmap>> mTextures;

private:
    TextureManager();
    static TextureManager* mInstance;
};

#endif // TEXTUREMANAGER_H

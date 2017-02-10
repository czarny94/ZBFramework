#include "spritemanager.h"
#include <QDebug>
#include <QCoreApplication>

SpriteManager* SpriteManager::mInstance=nullptr;

SpriteManager *SpriteManager::getInstance()
{
    if(!mInstance)
    {
        mInstance=new SpriteManager();
    }
    return mInstance;
}

std::shared_ptr<QPixmap> SpriteManager::getSprite(QString fileName)
{
    auto check=mSpritess.find(fileName);
    if(check==mSpritess.end())
    {
        return nullptr;
    }
    else
    {
        return check->second;
    }
}

std::shared_ptr<QPixmap> SpriteManager::loadSprite(QString fileName,const char *format , Qt::ImageConversionFlags flags)
{
    auto check=mSpritess.find(fileName);
    if(check!=mSpritess.end())
    {
        qDebug()<<fileName<<"textura juz załadowana";
        return check->second;
    }

    else
    {
        QPixmap* texture=new QPixmap();
        if (!texture)
        {
            throw(fileName+QString("nieudalo sie stworzyc QPixmap"));
        }
        QString currenthPath=QCoreApplication::applicationDirPath() ;
        if(!texture->load((currenthPath + "/" +fileName),format,flags))
        {
            throw(fileName+QString("Nie udało się załadować textury"));
            delete texture;
        }

        std::shared_ptr<QPixmap> tempPtr(texture);

        auto tempPair=std::make_pair(fileName,tempPtr);
        mSpritess.insert(tempPair);

        return tempPair.second;
    }
}

//bool TextureManager::insertTexture(QPixmap *texture, QString fileName)
//{
//    if (!texture)
//    {
//        throw(QString("pusty wskaznik"));
//        return false;
//    }
//    auto check=mTextures.find(fileName);
//    if(check!=mTextures.end())
//    {
//        throw(QString("podane id juz istnieje"));
//        return false;
//    }

//        std::shared_ptr<QPixmap> tempPtr(texture);
//        //std::pair<QString,std::shared_ptr<QPixmap>>
//        auto tempPair=std::make_pair(fileName,tempPtr);
//        mTextures.insert(tempPair);
//        return true;

//}

void SpriteManager::deleteSprite(QString fileName)
{
    auto texture=mSpritess.find(fileName);
    if(texture!=mSpritess.end())
    {
       if( texture->second.unique())
           mSpritess.erase(fileName);
    }
}

void SpriteManager::deleteAll()
{
    for(std::map<QString,std::shared_ptr<QPixmap>>::iterator obj=mSpritess.begin();obj!=mSpritess.end();++obj)
    {
        if( obj->second.unique())
            mSpritess.erase(obj);
    }

}

SpriteManager::~SpriteManager()
{
    mSpritess.clear();
}

SpriteManager::SpriteManager()
{

}

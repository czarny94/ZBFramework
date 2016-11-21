#include "texturemanager.h"
#include <QDebug>
#include <QCoreApplication>

TextureManager* TextureManager::mInstance=nullptr;

TextureManager *TextureManager::getInstance()
{
    if(!mInstance)
    {
        mInstance=new TextureManager();
    }
    return mInstance;
}

std::shared_ptr<QPixmap> TextureManager::getTexture(QString fileName)
{
    auto check=mTextures.find(fileName);
    if(check==mTextures.end())
    {
        return nullptr;
    }
    else
    {
        return check->second;
    }
}

std::shared_ptr<QPixmap> TextureManager::loadTexture(QString fileName,const char *format , Qt::ImageConversionFlags flags)
{
    auto check=mTextures.find(fileName);
    if(check!=mTextures.end())
    {
        qDebug()<<"textura juz załadowana";
        return check->second;
    }

    else
    {
        QPixmap* texture=new QPixmap();
        if (!texture)
        {
            throw(QString("nieudalo sie stworzyc QPixmap"));
        }
        QString currenthPath=QCoreApplication::applicationDirPath() ;
        if(!texture->load((currenthPath + "/" +fileName),format,flags))
        {
            throw(QString("Nie udało się załadować textury"));
            delete texture;
        }

        std::shared_ptr<QPixmap> tempPtr(texture);

        auto tempPair=std::make_pair(fileName,tempPtr);
        mTextures.insert(tempPair);

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

void TextureManager::deleteTexture(QString fileName)
{
    auto texture=mTextures.find(fileName);
    if(texture!=mTextures.end())
    {
       if( texture->second.unique())
           mTextures.erase(fileName);
    }
}

void TextureManager::deleteAll()
{
    for(std::map<QString,std::shared_ptr<QPixmap>>::iterator obj=mTextures.begin();obj!=mTextures.end();++obj)
    {
        if( obj->second.unique())
            mTextures.erase(obj);
    }

}

TextureManager::~TextureManager()
{
    mTextures.clear();
}

TextureManager::TextureManager()
{

}

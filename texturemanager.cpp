#include "texturemanager.h"

TextureManager* TextureManager::mInstance=nullptr;

TextureManager *TextureManager::getInstance()
{
    if(!mInstance)
    {
        mInstance=new TextureManager();
    }
    return mInstance;
}

std::shared_ptr<QPixmap> TextureManager::getTexture(QString id)
{
    auto check=mTextures.find(id);
    if(check==mTextures.end())
    {
        return nullptr;
    }
    else
    {
        return check->second;
    }
}

bool TextureManager::loadTexture(QString fileName, QString id,const char *format , Qt::ImageConversionFlags flags)
{
    QPixmap* texture=new QPixmap(fileName,format,flags);
    if (!texture)
    {
        throw(QString("nieudalo sie zaladowac QPixmap"));
        return false;
    }
    auto check=mTextures.find(id);
    if(check!=mTextures.end())
    {
        throw(QString("podane id juz istnieje"));
        return false;
    }


      //  mTextures.insert(std::pair<QString,std::shared_ptr<QPixmap>>(id,(std::move(texture))));//chyba nie ma konstruktora przenoszacego
        return true;

}

bool TextureManager::insertTexture(QPixmap *texture, QString id)
{
    if (!texture)
    {
        throw(QString("pusty wskaznik"));
        return false;
    }
    auto check=mTextures.find(id);
    if(check!=mTextures.end())
    {
        throw(QString("podane id juz istnieje"));
        return false;
    }

        std::shared_ptr<QPixmap> tempPtr(texture);
        //std::pair<QString,std::shared_ptr<QPixmap>>
        auto tempPair=std::make_pair(id,tempPtr);
        mTextures.insert(tempPair);
        return true;

}

void TextureManager::deleteTexture(QString id)
{
    auto texture=mTextures.find(id);
    if(texture!=mTextures.end())
    {
       if( texture->second.unique())
           mTextures.erase(id);
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

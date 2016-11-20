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

bool TextureManager::loadTexture(QString fileName,const char *format , Qt::ImageConversionFlags flags)
{
    QPixmap* texture=new QPixmap();

    if (!texture)
    {
        throw(QString("nieudalo sie stworzyc QPixmap"));
        return false;
    }

    auto check=mTextures.find(fileName);
    if(check!=mTextures.end())
    {
        throw(QString("podane id juz istnieje"));
        delete texture;
        return false;
    }
    if(!texture->load(fileName,format,flags))
    {
        throw(QString("Nie udało się załadować textury"));
        delete texture;
        return false;
    }

    std::shared_ptr<QPixmap> tempPtr(texture);

    auto tempPair=std::make_pair(fileName,tempPtr);
    mTextures.insert(tempPair);

    return true;

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

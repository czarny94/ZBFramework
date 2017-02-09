#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <QObject>
#include <memory>
#include <map>
#include <QString>

//template<class T>
//class ResourceManager : public QObject
//{
//    Q_OBJECT
//public:
//    /**Zwraca wskaznik na statyczna instancje*/
//    static ResourceManager* getInstance();
//    /**Wczytaj texture, rzuca wyjatki QString
//      *fileName sciezka do pliku
//      *id klucz do mapy
//      *format
//      *flags */
//    std::shared_ptr<T> getResource(QString id);
//    bool loadResource(QString fileName,QString id)=0;
//    /**przenosi texture utworzona poza menagerem, rzuca wyjatki QString*/
//    bool insertResource(T* texture, QString id)=0;
//    /**Usuwa pojedyncza texture jesli nie istnieja inne referencje poza ta z mapy*/
//    //replaceTexture();
//    void deleteresource(QString id);
//    /**Czysci cala mape*/
//    void deleteAll();
//    ~ResourceManager();
//  signals:

//  public slots:
//  protected:
//      std::map<QString,std::shared_ptr<T>> mResources;

//  private:
//      ResourceManager();
//      static ResourceManager* mInstance;
//};




//template<class T>
//ResourceManager<T>* ResourceManager<T>::mInstance=nullptr;
//template<class T>
//ResourceManager<T> *ResourceManager<T>::getInstance()
//{
//    if(!mInstance)
//    {
//        mInstance=new TextureManager();
//    }
//    return mInstance;
//}
//template<class T>
//std::shared_ptr<T> ResourceManager::getResource(QString id)
//{
//    auto check=mResources.find(id);
//    if(check==mResources.end())
//    {
//        return nullptr;
//    }
//    else
//    {
//        return check->second;
//    }
//}
//template<class T>
//bool ResourceManager::loadResource(QString fileName, QString id,)
//{
//    T* resource=new T();

//    if (!resource)
//    {
//        throw(QString("nieudalo sie stworzyc resource"+id));
//        return false;
//    }

//    auto check=mResources.find(id);
//    if(check!=mResources.end())
//    {
//        throw(QString(id+"podane id juz istnieje"));
//        delete resource;
//        return false;
//    }
//    if(!texture->load(fileName))
//    {
//        throw(QString("Nie udało się załadować textury"));
//        delete texture;
//        return false;
//    }

//    std::shared_ptr<T> tempPtr(resource);

//    auto tempPair=std::make_pair(id,tempPtr);
//    mResource.insert(tempPair);

//    return true;

//}
//template<class T>
//bool ResourceManager::insertResource(T* resource, QString id)
//{
//    if (!texture)
//    {
//        throw(QString(id+"pusty wskaznik"));
//        return false;
//    }
//    auto check=mResources.find(id);
//    if(check!=mresources.end())
//    {
//        throw(QString(id+"podane id juz istnieje"));
//        return false;
//    }

//        std::shared_ptr<T> tempPtr(resource);

//        auto tempPair=std::make_pair(id,tempPtr);
//        mResources.insert(tempPair);
//        return true;

//}
//template<class T>
//void ResourceManager::deleteResource(QString id)
//{
//    auto resource=mResources.find(id);
//    if(resource!=mResources.end())
//    {
//       if( resource->second.unique())
//           mResources.erase(id);
//    }
//}
//template<class T>
//void ResourceManager::deleteAll()
//{
//    for(std::map<QString,std::shared_ptr<T>>::iterator obj=mResources.begin();obj!=mResources.end();++obj)
//    {
//        if( obj->second.unique())
//            mResources.erase(obj);
//    }

//}
//template<class T>
//ResourceManager::~ResourceManager()
//{
//    mTextures.clear();
//}
//template<class T>
//ResourceManager::ResourceManager()
//{

//}
#endif // RESOURCEMANAGER_H

#include "AssetManager.hpp"

AssetManager* AssetManager::myInstance = nullptr;

AssetManager::AssetManager()
{

}

AssetManager::~AssetManager()
{

}

AssetManager* AssetManager::getInstance()
{
    if(!myInstance) {
        myInstance = new AssetManager;
    }

    return myInstance;
}

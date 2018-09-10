#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP

class AssetManager
{
    public:
        ~AssetManager();
        static AssetManager* getInstance();
    private:
        AssetManager();
        static AssetManager* myInstance;
};

#endif

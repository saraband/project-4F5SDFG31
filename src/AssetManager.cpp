#include "AssetManager.hpp"

AssetManager* AssetManager::myInstance = nullptr;

AssetManager::AssetManager()
    : myFonts       ({nullptr})
    , myTextures    ({nullptr})
{
    // Texture paths
    myTexturePaths[Texture::Test] = "assets/textures/test.jpg";

    // Font paths
    myFontPaths[Font::Main] = "assets/fonts/main.ttf";

    // Test zone
    for (unsigned int i(0); i < Texture::Count; ++i) {
        myTextures[i] = new sf::Texture;
        myTextures[i]->loadFromFile(myTexturePaths[i]);
    }
}

AssetManager::~AssetManager()
{
    for (unsigned int i(0); i < Texture::Count; ++i) {
        if (myTextures[i]) {
            delete myTextures[i];
        }
    }
}

AssetManager* AssetManager::getInstance()
{
    if (!myInstance) {
        myInstance = new AssetManager;
    }

    return myInstance;
}

const sf::Texture& AssetManager::texture(Texture::Type type) const
{
    assert(
        type >= 0 &&
        type < Texture::Count &&
        myTextures[type] != nullptr
    );

    return *myTextures[type];
}

const sf::Font& AssetManager::font(Font::Type type) const
{
    assert(
        type >= 0 &&
        type < Font::Count &&
        myFonts[type] != nullptr
    );

    return *myFonts[type];
}
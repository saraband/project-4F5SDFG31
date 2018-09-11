#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

namespace Font
{
enum Type
{
    Main = 0,
    Count
};
}

namespace Texture
{
enum Type
{
    Test = 0,
    Count
};
}

class AssetManager
{
    public:
        ~AssetManager();
        static AssetManager* getInstance();
        bool loadAll();
        const sf::Texture& texture(Texture::Type type) const;
        const sf::Font& font(Font::Type type) const;
    private:
        AssetManager();
        static AssetManager*    myInstance;
        sf::Font*               myFonts[Font::Count];
        sf::Texture*            myTextures[Texture::Count];
        std::string             myFontPaths[Font::Count];
        std::string             myTexturePaths[Texture::Count];
};

#endif

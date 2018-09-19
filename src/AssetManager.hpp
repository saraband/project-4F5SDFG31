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
        static AssetManager*    m_instance;
        sf::Font*               m_fonts[Font::Count];
        sf::Texture*            m_textures[Texture::Count];
        std::string             m_fontPaths[Font::Count];
        std::string             m_texturePaths[Texture::Count];
};

#endif

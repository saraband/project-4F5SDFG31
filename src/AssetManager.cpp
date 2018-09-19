#include "AssetManager.hpp"

AssetManager* AssetManager::m_instance = nullptr;

AssetManager::AssetManager()
    : m_fonts       ({nullptr})
    , m_textures    ({nullptr})
{
    // Texture paths
    m_texturePaths[Texture::Test] = "assets/textures/test.jpg";

    // Font paths
    m_fontPaths[Font::Main] = "assets/fonts/main.ttf";

    // Test zone
    for (unsigned int i(0); i < Texture::Count; ++i) {
        m_textures[i] = new sf::Texture;
        m_textures[i]->loadFromFile(m_texturePaths[i]);
    }
}

AssetManager::~AssetManager()
{
    for (unsigned int i(0); i < Texture::Count; ++i) {
        if (m_textures[i]) {
            delete m_textures[i];
        }
    }
}

AssetManager* AssetManager::getInstance()
{
    if (!m_instance) {
        m_instance = new AssetManager;
    }

    return m_instance;
}

const sf::Texture& AssetManager::texture(Texture::Type type) const
{
    assert(type >= 0);
    assert(type < Texture::Count);
    assert(m_textures[type] != nullptr);

    return *m_textures[type];
}

const sf::Font& AssetManager::font(Font::Type type) const
{
    assert(type >= 0);
    assert(type < Font::Count);
    assert(m_fonts[type] != nullptr);

    return *m_fonts[type];
}
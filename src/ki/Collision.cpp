#include "Collision.hpp"

namespace ki
{
bool boxCollide(const sf::FloatRect& bounds1, const sf::FloatRect& bounds2)
{
    if (bounds1.left + bounds1.width < bounds2.left ||
        bounds1.left > bounds2.left + bounds2.width ||
        bounds1.top + bounds1.height < bounds2.top ||
        bounds1.top > bounds2.top + bounds2.height)
        return false;
    return true;
}

inline const sf::Uint8* pixelAt(const sf::Uint8* pixels, const sf::Vector2i& pos, const sf::Vector2i& size)
{
    return (const sf::Uint8*)pixels[pos.y * size.x * 4 + pos.x * 4];
}

bool pixelCollide(const sf::Vector2f& pos1, const sf::Uint8* pixels1, const sf::Vector2f& pos2, const sf::Uint8* pixels2)
{
    // TODO
    return false;
}
}
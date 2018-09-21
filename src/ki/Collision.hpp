#ifndef KI_COLLISION_HPP
#define KI_COLLISION_HPP

#include <SFML/Graphics.hpp>

namespace ki
{
bool boxCollide(const sf::FloatRect& bounds1, const sf::FloatRect& bounds2);
inline const sf::Uint8* pixelAt(const sf::Uint8* pixels, const sf::Vector2i& pos, const sf::Vector2i& size);
bool pixelCollide(const sf::Vector2f& pos1, const sf::Uint8* pixels1, const sf::Vector2f& pos2, const sf::Uint8* pixels2);
}

#endif
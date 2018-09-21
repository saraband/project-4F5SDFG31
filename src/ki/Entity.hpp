#ifndef KI_ENTITY_HPP
#define KI_ENTITY_HPP

#include <SFML/Graphics.hpp>

namespace ki
{
class Entity
{
    public:
        Entity();
        virtual ~Entity();
        virtual void update(float elapsed) = 0;
    protected:
        sf::Vector2f    m_position;
        sf::Vector2f    m_size;
};
}

#endif
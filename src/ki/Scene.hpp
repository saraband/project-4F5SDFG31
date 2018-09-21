#ifndef WORLD_HPP
#define WORLD_HPP

#include <list>
#include "Entity.hpp"
#include "Collision.hpp"

namespace ki
{
class Scene
{
    public:
        Scene();
        ~Scene();
        void update();
    private:
        sf::Clock           m_clock;
        std::list<Entity*>  m_entities;
};
}

#endif
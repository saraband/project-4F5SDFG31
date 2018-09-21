#include "Scene.hpp"

namespace ki
{
Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::update()
{
    float elapsed = m_clock.getElapsedTime().asSeconds();
    std::for_each(m_entities.begin(), m_entities.end(), [=, elapsed](Entity* entity) {
        entity->update(elapsed);
    });
    m_clock.restart();
}
}
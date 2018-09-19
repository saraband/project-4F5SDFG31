#include "Manager.hpp"

namespace ui
{
Manager::Manager(sf::RenderWindow& window)
    : m_window  (window)
{

}

Manager::~Manager()
{

}

void Manager::processEvent(const sf::Event& event)
{
    switch (event.type) {
        case sf::Event::MouseButtonPressed:
            for (auto it = m_elements.begin(); it != m_elements.end(); ++it) {
                if ((*it)->m_bounds.contains(sf::Mouse::getPosition(m_window))) {
                    (*it)->m_onClick();
                }
            }
    }
}

void Manager::addElement(Element* element)
{
    m_elements.push_back(element);
}

void Manager::draw(sf::RenderWindow& window)
{
    for (auto it = m_elements.begin(); it != m_elements.end(); ++it)
        window.draw(**it);
}
}
#include "Manager.hpp"

namespace ui
{
Manager::Manager(sf::RenderWindow& window)
    : m_window          (window)
    , m_activeElement   (nullptr)
{

}

Manager::~Manager()
{

}

void Manager::processEvent(const sf::Event& event)
{
    switch (event.type) {
        case sf::Event::MouseButtonPressed:
            // Iterate every element from the higher z-index to the lower
            // If the mouse event is inside the element, triggers its
            // onClick hook
            std::for_each(m_elements.begin(), m_elements.end(), [this](Element* element) {
                if (element->m_bounds.contains(sf::Mouse::getPosition(m_window))) {
                    element->m_onClick();
                }
            });
            return;
    }
}

void Manager::addElement(Element* element)
{
    // Insert element before the first element with a lower z-index
    // So they are always sorted from high z-index to low
    for (auto it = m_elements.begin(); it != m_elements.end(); ++it) {
        if ((*it)->m_zIndex < element->m_zIndex) {
            m_elements.insert(it, element);
            return;
        }
    }

    m_elements.push_back(element);
}

void Manager::draw(sf::RenderWindow& window)
{
    std::for_each(m_elements.begin(), m_elements.end(), [&window](Element* element) {
        window.draw(*element);
    });
}
}
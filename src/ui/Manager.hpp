#ifndef UI_MANAGER_HPP
#define UI_MANAGER_HPP

#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Element.hpp"

namespace ui
{
class Manager
{
    public:
        Manager(sf::RenderWindow& window);
        ~Manager();
        void processEvent(const sf::Event& event);
        void addElement(Element* element);
        void draw(sf::RenderWindow& window);
    private:
        sf::RenderWindow&       m_window;
        std::vector<Element*>   m_elements;
        Element*                m_activeElement;
};
}

#endif
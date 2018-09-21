#ifndef UI_BUTTON_HPP
#define UI_BUTTON_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "Element.hpp"

namespace ui
{
class Button : public Element
{
    public:
        Button(const std::string& label, const sf::FloatRect& bounds, int zIndex = -1);
        virtual ~Button();
    protected:
        virtual const char* type() const;
        virtual void update();
        virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
        sf::RectangleShape  m_sprite;
        sf::Font            m_font;
        sf::Text            m_text;
};
}

#endif
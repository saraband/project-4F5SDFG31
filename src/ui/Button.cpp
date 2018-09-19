#include "Button.hpp"

namespace ui
{
Button::Button(const std::string& label, const sf::FloatRect& bounds, int zIndex)
    : Element   (bounds, zIndex)
{
    m_font.loadFromFile("assets/fonts/main.ttf");
    m_text.setFont(m_font);
    m_text.setCharacterSize(20);
    m_text.setString(label);
    m_sprite.setSize(sf::Vector2f(bounds.width, bounds.height));
    m_sprite.setFillColor(sf::Color::Green);
    m_sprite.setPosition(sf::Vector2f(bounds.left, bounds.top));
}

Button::~Button()
{

}

void Button::evolve()
{

}

void Button::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    //states.transform = states.transform.combine(getTransform());
    window.draw(m_sprite, states);
}
}
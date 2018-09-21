#include "Button.hpp"

namespace ui
{
Button::Button(const std::string& label, const sf::FloatRect& bounds, int zIndex)
    : Element   (bounds, zIndex)
{
    m_font.loadFromFile("assets/fonts/main.ttf");
    m_text.setFont(m_font);
    m_text.setColor(sf::Color::White);
    m_text.setCharacterSize(20);
    m_text.setString(label);
    m_sprite.setSize(sf::Vector2f(bounds.width, bounds.height));
    m_sprite.setFillColor(sf::Color::Blue);
    m_sprite.setPosition(sf::Vector2f(bounds.left, bounds.top));

    // Center the text inside the button
    // TODO: bunch of helpers for this later ?
    sf::FloatRect b = m_text.getGlobalBounds();
    m_text.setPosition(sf::Vector2f(
        m_sprite.getPosition().x + (m_sprite.getSize().x / 2) - (b.width / 2),
        m_sprite.getPosition().y + (m_sprite.getSize().y / 2) - (b.height / 2) - 10
    ));
}

Button::~Button()
{

}

const char* Button::type() const
{
    return "Button";
}

void Button::update()
{

}

void Button::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    //states.transform = states.transform.combine(getTransform());
    window.draw(m_sprite, states);
    window.draw(m_text, states);
}
}
#include "Input.hpp"

namespace ui
{
Input::Input(const sf::FloatRect& bounds, int zIndex)
    : Element   (bounds, zIndex)
{

}

Input::~Input()
{

}

const char* Input::type() const
{
    return "Input";
}

void Input::update()
{

}

void Input::draw(sf::RenderTarget& window, sf::RenderStates states) const
{

}

}
#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>
#include "Element.hpp"

namespace ui
{
class Input : public Element
{
    public:
        Input(const sf::FloatRect& bounds, int zIndex = -1);
        virtual ~Input();
    private:
        virtual const char* type() const;
        virtual void update();
        virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
        std::string     m_input;
};
}

#endif
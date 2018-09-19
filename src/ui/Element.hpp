#ifndef UI_ELEMENT_HPP
#define UI_ELEMENT_HPP

#include <functional>
#include <SFML/Graphics.hpp>
#include "Event.hpp"

namespace ui
{
class Manager;
class Element : public sf::Drawable, public sf::Transformable
{
    public:
        Element(const sf::FloatRect& bounds, int zIndex = -1);
        virtual ~Element();
        void bindEvent(Event::Type type, const std::function<void()>& hook);
    protected:
        friend class Manager;
        static int                 m_zIndexCounter;
        int                        m_zIndex;
        sf::IntRect                m_bounds;
        std::function<void()>      m_onClick;
        std::function<void()>      m_onKeyPress;
        std::function<void()>      m_onResize;
    private:
        virtual void evolve() = 0;
        virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;
};
}


#endif
#include "Element.hpp"

namespace ui
{
int Element::m_zIndexCounter = 0;

Element::Element(const sf::FloatRect& bounds, int zIndex)
    : m_zIndex      (m_zIndexCounter++)
    , m_bounds      (bounds)
    , m_onClick     ([](){})
    , m_onKeyPress  ([](){})
    , m_onResize    ([](){})
{

}

Element::~Element()
{

}

void Element::bindEvent(Event::Type type, const std::function<void()>& hook)
{
    switch (type) {
        case Event::Click:
            m_onClick = hook;
            return;
        case Event::KeyPress:
            m_onKeyPress = hook;
            return;
    }
}
}
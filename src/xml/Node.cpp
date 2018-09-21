#include "Node.hpp"

namespace xml
{
Node::Node(NodeType type, const std::string& str)
    : m_type            (type)
    , m_tag             ("[default tag]")
    , m_text            ("[default text]")
    , m_previous        (nullptr)
    , m_next            (nullptr)
    , m_parent          (nullptr)
    , m_firstChild      (nullptr)
    , m_lastChild       (nullptr)
{
    if (type == NODE)
        m_tag = str;
    else
        m_text = str;
}

Node::~Node()
{
    if (m_next)
        delete m_next;
    if (m_firstChild)
        delete m_firstChild;
}

Node* Node::appendChild(Node* child)
{
    assert(child != nullptr);

    // No children yet
    if (!m_firstChild) {
        m_firstChild = child;
        m_lastChild = child;
        child->m_parent = this;
        return child;
    }

    // Already has children
    m_lastChild->m_next = child;
    child->m_previous = m_lastChild;
    child->m_parent = this;
    m_lastChild = child;
    return child;
}

Node* Node::appendSibling(Node* sibling)
{
    assert(sibling != nullptr);

    // TODO
    m_next = sibling;
    sibling->m_previous = this;
    sibling->m_parent = m_parent;
    return sibling;
}
}
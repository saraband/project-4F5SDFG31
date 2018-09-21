#ifndef XML_NODE_HPP
#define XML_NODE_HPP

#include <string>
#include <iostream>
#include <cassert>

namespace xml
{
enum NodeType
{
    TEXT,
    NODE
};

class Document;
class Node
{
    public:
        Node(NodeType type, const std::string& str = "");
        ~Node();
        Node* appendChild(Node* child);
        Node* appendSibling(Node* sibling);
    private:
        friend class Document;
        NodeType        m_type;
        std::string     m_tag;
        std::string     m_text;
        Node*           m_previous;
        Node*           m_next;
        Node*           m_parent;
        Node*           m_firstChild;
        Node*           m_lastChild;
};
}

#endif
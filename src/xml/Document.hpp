#ifndef XML_DOCUMENT_HPP
#define XML_DOCUMENT_HPP

#include <iostream>
#include <functional>
#include <fstream>
#include <string>
#include "Node.hpp"

namespace xml
{
class Document
{
    public:
        Document();
        Document(const std::string& filename);
        ~Document();
        void destroy();
        void dump() const;
        bool loadFromFile(const std::string& filename);
        bool saveToFile(const std::string& filename) const;
        Node* root() const;
    private:
        Node*   m_root;
        bool isWhiteSpace(char c) const;
};
}

#endif
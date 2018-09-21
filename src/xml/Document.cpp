#include "Document.hpp"

namespace xml
{
Document::Document()
    : m_root    (nullptr)
{
    // TEMPORARY
    m_root = new Node(NODE, "Root");
}

Document::Document(const std::string& filename)
    : Document()
{
    loadFromFile(filename);
}

Document::~Document()
{
    destroy();
}

bool Document::loadFromFile(const std::string& filename)
{
    return true;
}

bool Document::saveToFile(const std::string& filename) const
{
    std::ofstream file(filename);

    if (!file) {
        std::cerr << "Unable to save to file '" << filename << "'" << std::endl;
        return false;
    }

    std::function<void(Node*, int)> saveNode = [&saveNode, &file](Node* node, int depth) {
        if (!node)
            return;

        for (int d = depth; d > 0; --d)
            file << '\t';
        file << '<' << node->m_tag << '>' << '\n';

        saveNode(node->m_firstChild, depth + 1);
        saveNode(node->m_next, depth);

        for (int d = depth; d > 0; --d)
            file << '\t';
        file << "</" << node->m_tag << '>' << '\n';
    };

    saveNode(m_root, 0);

    file.close();
    return true;
}

void Document::destroy()
{
    if (m_root)
        delete m_root;
}

void Document::dump() const
{
    if (!m_root) {
        std::cerr << "Unable to dump: Document is empty." << std::endl;
        return;
    }

    std::function<void(Node*, int)> dumpNode = [&dumpNode](Node* node, int depth) {
        if (!node)
            return;

        for (int d = depth; d > 0; --d)
            std::cout << "==";

        std::cout << "== " << node->m_tag << std::endl;

        dumpNode(node->m_firstChild, depth + 1);
        dumpNode(node->m_next, depth);
    };

    dumpNode(m_root, 0);
}

Node* Document::root() const
{
    return m_root;
}
}
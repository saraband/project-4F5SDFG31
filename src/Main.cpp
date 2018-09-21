#include "App.hpp"
#include "xml/Document.hpp"

int main(int argc, char** argv)
{
    xml::Document doc;
    doc.root()->appendChild(new xml::Node(xml::NODE, "Parent1"))
        ->appendChild(new xml::Node(xml::NODE, "Child1"))
        ->appendSibling(new xml::Node(xml::NODE, "Child2"))
        ->appendSibling(new xml::Node(xml::NODE, "Child3"));
    doc.root()->appendChild(new xml::Node(xml::NODE, "Parent2"))
        ->appendChild(new xml::Node(xml::NODE, "Child1"))
        ->appendSibling(new xml::Node(xml::NODE, "Child2"))
        ->appendSibling(new xml::Node(xml::NODE, "Child3"));

    doc.dump();
    doc.saveToFile("save.xml");
    return 0;
	//return App::getInstance()->launch();
}

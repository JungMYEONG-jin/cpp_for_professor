#include <vector>
#include <string>
#include <Element.h>

class Node{
    std::vector<Node*> child;
    std::string nodeType;
    Element* element;
public:
    Node() {}

    Node(std::vector<Node*> child, std::string nodeType, Element* element){
        this->child = child;
        this->nodeType = nodeType;
        this->element = element;
    }

    Node* createText(std::string data){
        std::vector<Node*> init;
        return new Node(init, data, NULL);
    }

    Node* createElement(std::string name, std::map<std::string, std::string> attributes, std::vector<Node*> child){
        return new Node(child, "", new Element(name, attributes));
    }
};

#include <vector>
#include <string>
#include <map>

class Element{
    std::string tagName;
    std::map<std::string, std::string> attributes;

public:
    Element() {}
    Element(std::string tagName, std::map<std::string, std::string> attributes){
        this->tagName = tagName;
        this->attributes = attributes;
    }
    
    std::string getId(){
        return this->attributes["id"];
    }

    std::string getClasses(){
        return this->attributes["class"];
    }
};

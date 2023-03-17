#include <string>
#include <Node.h>

using namespace std;



class HtmlParser{
    string input;
    int idx;
public:
    HtmlParser() {}
    HtmlParser(string input, int idx){
        this->input = input;
        this->idx = idx;
    }

    // 현재 인덱스의 문자
    char getCharacter(){
        return this->input[idx];
    }

    // 현재 인덱스에서부터의 문자열들이 파라미터 문자열로 시자하는지 판단하는 메소드
    bool isStartsWith(string str){
        int curIdx = this->idx;
        int len = str.size();
        for(int i=0;i<len;i++){
            if(str[i] != input[curIdx++])
                return false;
        }
        return true;
    }

    // 현재 위치가 input의 끝을 가리키는지 판단.
    bool isEndOfInput(){
        return this->idx >= this->input.length();
    }

    char consumeCharacter(){
        int curIdx = this->idx;
        char curCharacter = this->input[idx];
        this->idx++;

        return curCharacter;
    }

    string consumeWhile(){
        string result = "";
        while(!isEndOfInput()){
            result += consumeCharacter();
        }
        return result;
    }

    void consumeWhitespace(){
        while(!isEndOfInput() && checkSpace(getCharacter()))
        {
            consumeCharacter();
        }
    }

    string doUntilNotEuqal(char ch){
        string result = "";
        while(!isEndOfInput() && ch != getCharacter()){
            result += consumeCharacter();
        }
        return result;
    }

    bool checkSpace(char ch){
        return ch == ' ' ? true : false;
    }

    // 숫자, lower, upper alpha 인지 체크
    bool checkIndexof(char ch){
        if(isdigit(ch) || islower(ch) || isupper(ch))
            return true;
        return false;
    }

    Node* parse(){
        auto nodes = parseNodes();
        if(nodes.size() == 1)
        {
            auto it = nodes.back();
            nodes.pop_back();
            return it;
        }
        return createElement("html", {}, nodes);
    }

    vector<Node*> parseNodes(){
        vector<Node*> result;
        while(true){
            consumeWhitespace(); // 공백제거

            if(isEndOfInput() || isStartsWith("</"))
                break;
            result.push_back(parseNode());
        }
        return result;
    }

    Node* parseNode(){
        if (getCharacter() == '<')
            return parseElement();
        return parseText();    
    }

    Node* parseElement(){
        string tagName = parseName();
        map<string, string> attr = parseAttributes();
        vector<Node*> child = parseNodes();
        return createElement(tagName, attr, child);
    }

    string parseName(){
        string result = "";
        while(!isEndOfInput() && checkIndexof(getCharacter()))
        {
            result += consumeCharacter();
        }
        return result;
    }

    map<string, string> parseAttributes(){
        map<string, string> attr;
        while(true){
            consumeWhitespace();
            if(getCharacter() == '>')
                break;
            pair<string, string> info = parseAttr();
            string key = info.first;
            string value = info.second;
            attr[key] = value;
        }
        return attr;
    }

    pair<string, string> parseAttr(){
        string name = parseName();
        string value = parseAttrValue();
        return make_pair<string, string>(name, value);
    }

    string parseAttrValue(){
        char quote = consumeCharacter();
        string value = doUntilNotEuqal(quote);
        return value;
    }

    string doUntilNotOpen(){
        string result = "";
        while(!isEndOfInput() && getCharacter() != '<'){
            result += consumeCharacter();
        }
        return result;
    }

    Node* parseText(){
        string data = doUntilNotOpen();
        return createText(data);
    }
};

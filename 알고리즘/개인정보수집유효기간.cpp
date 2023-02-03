#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> db;
    for(auto term : terms){
        int idx = term.find(' ');
        db[term[0]] = stoi(term.substr(idx+1));
    }
    
    int year = stoi(today.substr(0, 4));
    int month = stoi(today.substr(5, 7));
    int day = stoi(today.substr(8));
    
    year *= 10000;
    month *= 100;
    
    int val = year + month + day;
    int num = 1;
    for(string privacy : privacies){
        int idx = privacy.find(' ');
        
        string df = privacy.substr(0, idx);
        string code = privacy.substr(idx+1);
        
        int to = db[code[0]];
        
        int pYear = stoi(df.substr(0, 4));
        int pMonth = stoi(df.substr(5, 7));
        int pDay = stoi(df.substr(8));
        
        pMonth += to;
        
        if(pMonth>12){
            pYear+=pMonth/12;
            pMonth%=12;
        }
        pDay-=1;
        if(pDay==0){
            pMonth-=1;
            pDay = 28;
        }
        if(pMonth==0){
            pYear-=1;
            pMonth = 12;
        }
        
        pYear *= 10000;
        pMonth *= 100;
    
        int temp = pYear + pMonth + pDay;
        if(temp<val)
            answer.push_back(num);
        
        num++;
            
    }
    
    
    return answer;
}

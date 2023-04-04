#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <map>

using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    // sort by start time
    sort(plans.begin(), plans.end(), [](auto it, auto it2){
        return it[1]<it2[1];
    });
    // set time table
    map<string, pair<int, int>> table;
    for(const auto& it : plans){
        int idx = it[1].find(':');
        int hour = stoi(it[1].substr(0, idx));
        int minute = stoi(it[1].substr(idx+1));
        table[it[0]] = {60*hour + minute, stoi(it[2])};
    }
    
    // use stack
    stack<string> db;
    for(int i=0;i<1440;i++){
        for(const auto& it : plans){
            if(table[it[0]].first==i){
                db.push(it[0]);
                break;
            }
        }
        if(!db.empty()){
            table[db.top()].second--;
            if(table[db.top()].second == 0)
            {
                answer.push_back(db.top());
                db.pop();
            }
        }
    }
    
    while(!db.empty()){
        answer.push_back(db.top());
        db.pop();
    }
    
    
    return answer;
}

```c++
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <map>

using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    // sort by start time
    sort(plans.begin(), plans.end(), [](auto it, auto it2){
        return it[1]<it2[1];
    });
    // set time table
    map<string, int> table;
    
    
    // use stack
    stack<string> db;
    int time = 0;
    for(const auto& it : plans){
        int idx = it[1].find(':');
        int hour = stoi(it[1].substr(0, idx));
        int minute = stoi(it[1].substr(idx+1));
        int nextTime = 60 * hour + minute;
        while(!db.empty()){
            string name = db.top();
            db.pop();
            int times = table[name];
            table[name] -= nextTime - time;
            
            if(table[name]<=0){
                answer.push_back(name);
                time+=times;
            }else{
                db.push(name);
                break;
            }
        }
        time = nextTime;
        table[it[0]] = stoi(it[2]);
        db.push(it[0]);
    }
    
    
    while(!db.empty()){
        answer.push_back(db.top());
        db.pop();
    }
    
    
    return answer;
}    
    
```

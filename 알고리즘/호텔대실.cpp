#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool isValid(string left, string right){
    int lh = stoi(left.substr(0, 2));
    int lm = stoi(left.substr(3));

    int rh = stoi(right.substr(0, 2));
    int rm = stoi(right.substr(3));

    rm -= 10;
    if(rm<0){
        rm+=60;
        rh-=1;
    }

    int lvalue = lh*60 + lm;
    int rvalue = rh*60 + rm;
    return rvalue>=lvalue;
}



int solution(vector<vector<string>> book_time) {
    int answer = 0;
    sort(book_time.begin(), book_time.end(), [](auto it, auto it2){
        return it[0] < it2[0];
    });

    int len = book_time.size();
    vector<bool> visited(len, false);
    map<int, vector<vector<string>>> db;

    for(int i=0;i<len;i++){
        if(!visited[i]){
            vector<vector<string>> temp;
            db[i] = temp;
            db[i].push_back(book_time[i]);
        }else
            continue;
        for(int j=i+1;j<len;j++){
            if(!visited[j] && isValid(db[i].back()[1], book_time[j][0]))
            {
                db[i].push_back(book_time[j]);
                visited[j] = true;
            }
        }
    }
    answer = db.size();
    return answer;
}

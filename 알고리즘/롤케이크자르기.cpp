#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <map>
#include <set>

#define INF 999999999

using namespace std;

// 첫째로 공평해지는걸 찾고 나서 그 이후로 증가시킨다
// 만약 어느순간 공평해지지 않다면 더이상 불가한것임
int solution(vector<int> topping) {
    int answer = 0;
    set<int> temp;
    map<int, int> db;
    for(int i : topping){
        db[i]++;
    }
    bool firstStart = false;
    for(int i : topping){
        db[i]-=1;
        temp.insert(i);
        if (db[i]==0)
        {
            /* code */
            db.erase(i);
        }
        if (!firstStart && db.size()==temp.size())
        {
            /* code */
            answer++;
            firstStart = true;
        }else if(firstStart && db.size()==temp.size()){
            answer++;
        }else if(firstStart && !(db.size()==temp.size()))
        {
            break;
        }
        
        
    }

    return answer;
}

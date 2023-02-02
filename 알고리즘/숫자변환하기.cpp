#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

void dfs(int x, int y, int n, queue<int>& q, set<int>& s){
    if(x+n<=y && !s.count(x+n)){
        s.insert(x+n);
        q.push(x+n);
    }
    if(2*x<=y && !s.count(2*x)){
        s.insert(2*x);
        q.push(2*x);
    }
    if(3*x<=y && !s.count(3*x)){
        s.insert(3*x);
        q.push(3*x);
    }
    return;
}


int solution(int x, int y, int n) {
    if(x == y)
        return 0;
    int answer = 0;
    queue<int> q;
    q.push(x);
    set<int> s;
    int cnt = 0;
    while(!q.empty()){
        int qsize = q.size();
        for(int i=0;i<qsize;i++){
            int cur = q.front();
            q.pop();
            if(cur==y)
                return cnt;
            dfs(cur, y, n, q, s);            
        }
        cnt++;
    }
    return -1;
}

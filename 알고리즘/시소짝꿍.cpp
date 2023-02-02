#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    map<int, vector<int>> db;
    set<int> res;
    for(int w : weights){
        if(db.find(w) == db.end()){
            vector<int> temp;
            temp.push_back(w);
            db[w] = temp;
        }else
            db[w].push_back(w);
        res.insert(w);
    }
    
    long long ans = 0;
    
    for(auto it : res){
        int w = it;
        // 2w
        long dup = db[it].size();
        int w2 = 2*w;
        if(w2%3 == 0 && db.find(w2/3)!=db.end()){
            ans += db[w2/3].size() * dup;
        }
        if(w2%4 == 0 && db.find(w2/4)!=db.end()){
            ans += db[w2/4].size() * dup;
        }
        int w3 = 3*w;
        if(w3%2 == 0 && db.find(w3/2)!=db.end()){
            ans += db[w3/2].size() * dup;
        }
        if(w3%4 == 0 && db.find(w3/4) != db.end()){
            ans += db[w3/4].size() * dup;
        }
        int w4 = 4*w;
        if(w4%2 == 0 && db.find(w4/2)!=db.end()){
            ans+=db[w4/2].size() * dup;
        }
        if(w4%3 == 0 && db.find(w4/3) != db.end()){
            ans+=db[w4/3].size() * dup;
        }
        
        if(dup>1){
            ans+=(dup * (dup-1))/2;
        }
        db.erase(w);
    }
    return ans;
}

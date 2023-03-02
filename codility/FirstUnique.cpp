#include <algorithm>
#include <map>


// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    map<int, vector<int>> db;
    int len = A.size();
    for(int i=0;i<len;i++){
        db[A[i]].push_back(i);
    }
    vector<pair<int, int>> res;
    for(auto& it : db){
        if(it.second.size()==1){
            res.push_back({it.second[0], it.first});
        }
    }
    if(!res.empty()){
        sort(res.begin(), res.end(), [](auto it, auto it2){
            return it.first<it2.first;
        });
        return res[0].second;
    }

    return -1;
}

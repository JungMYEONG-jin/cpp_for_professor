#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int solution(vector<int> food_times, long long k) {

    map<int, int> db;
    set<int> kind;
    int len = food_times.size();
    for(auto i : food_times)
    {
        db[i]++;
        kind.insert(i);
    }
    long long sumval = 0;
    long long cnt = len;
    long long now, prev = 0;
    for(auto& d : kind)
    {
        now = d;
        long long temp = (now-prev)*cnt;
        if(sumval+temp>k)
            break;
        sumval+=temp;
        cnt-=db[d];
        prev = now;
        
    }
    if(cnt==0)
        return -1;
    
    long long idx = k-sumval;
    vector<pair<int, int>> res;
    for(int i=0;i<len;i++)
    {
        if(food_times[i]>=now)
            res.push_back({food_times[i],i+1});
    }
    int index = idx%res.size();
    
    
    
    return res[index].second;
    
}

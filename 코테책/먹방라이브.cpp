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

    long long sval = 0;
    for(auto i : food_times)
        sval+=i;
    if(sval<=k)
        return -1;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int cnt = 0;
    long long len = food_times.size();
    for(int i=0;i<len;i++)
        pq.push({food_times[i], i+1});
    
    
    sval = 0;
    long long prev = 0;
    
    
    while(sval+((pq.top().first-prev)*len)<=k)
    {
        auto cur = pq.top();
        pq.pop();
        sval+=(cur.first-prev)*len;
        len--;
        prev = cur.first;
    }
    
    vector<pair<int, int>> res;
    while(!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }
    
    sort(res.begin(), res.end(), [](auto e, auto k){return e.second<k.second;});
    
    return res[(k-sval)%len].second;
    
    
    
    
}

```c++
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> remain;
        int ans = 0;
    for(int i=0, len = capacity.size();i<len;i++){
        if(capacity[i] == rocks[i]){
            ans++;
            continue;
        }else
            remain.push_back(capacity[i] - rocks[i]);
    }
    sort(remain.begin(), remain.end());
    
    for(auto x : remain){
        if(additionalRocks<x)
            break;
        additionalRocks-=x;
        ans++;
    }
    return ans;
    }
};
```

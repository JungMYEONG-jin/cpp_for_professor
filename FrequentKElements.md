```c++
vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> db;
    for(int num : nums)
        db[num]++;
    vector<pair<int, int>> res;
    for(const auto& it : db){
        res.push_back({it.first, it.second});
    }

    sort(res.begin(), res.end(), [](auto left, auto right){
        return left.second > right.second;
    });
    vector<int> ans;
    for(int i=0;i<k;i++){
        ans.push_back(res[i].first);
    }
    return ans;
}
```

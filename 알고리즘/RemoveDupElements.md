## 구현


```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> db;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};
```

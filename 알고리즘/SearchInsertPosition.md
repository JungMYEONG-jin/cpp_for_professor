## leetcode 1일차


```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return it-nums.begin();
    }
};
```

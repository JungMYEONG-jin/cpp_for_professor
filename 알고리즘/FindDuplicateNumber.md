```c++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int start = 1;
    int end = nums.size() - 1;
    int mid;
    while (start <= end) {
        mid = (start + end) >> 1;
        int cnt = 0;
        for (auto num : nums) {
            if (num <= mid)
                cnt++;
        }

        if (mid >= cnt) {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    return start;
    }
};
```

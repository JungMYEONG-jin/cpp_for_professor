## 카데인 알고리즘 사용하여 부분수열합 최대 구하기

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int res = nums[0];
        int val = nums[0];
        for(int i=1;i<len;i++){
            val = max(val+nums[i], nums[i]);
            res = max(res, val);
        }
        return res;
    }
};
```

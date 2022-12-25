## DP
i번째에 이전꺼를 털면 인접한거 두개 털어서 걸리니까 점화식은 다음과 같이 세울 수 있다. dp[i] = max(dp[i-1], dp[i-2]+nums[i])

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len==1)
            return nums[0];

        int ans = 0;
        nums[1] = max(nums[0], nums[1]);
        for(int i=2;i<len;i++){
            nums[i] = max(nums[i-1], nums[i-2]+nums[i]);
        }
        return nums[len-1];
    }
};
```

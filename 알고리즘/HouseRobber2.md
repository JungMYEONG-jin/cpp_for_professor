## 원형 연결된 도둑질

시작점과 끝점이 연결되므로

두가지 경우로 생각하자.

1 시작점에 출발
2 시작점을 하지 않고 그다음에 시작.

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        int dp[101] = {0, };
        int dp2[101] = {0, };
        dp[0] = nums[0];
        dp[1] = nums[0];
        dp2[0] = 0;
        dp2[1] = nums[1];
        for(int i=2;i<n;i++){
            
            if(i!=n-1){
                dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
            }
            dp2[i] = max(dp2[i-2]+nums[i], dp2[i-1]);
        }
        return max(dp[n-2], dp2[n-1]);
    }
};
```

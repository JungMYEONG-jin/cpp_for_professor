## DP

1~n까지 차례대로 구해보면 규칙이 있음.

```c++
class Solution {
public:

    int dp[46];

    int climbStairs(int n) {
        // 1 1
        // 2 2
        // 3 3
        // 4 5
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};
```

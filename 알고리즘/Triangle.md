## DP

처음, 끝 그리고 그외부분을 구분해서 구해주면된다.

```c++
class Solution {
public:
    int dp[201][201];
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        dp[0][0] = triangle[0][0];
        if(row==1)
            return dp[0][0];
        int ans = 999999999;
        for(int i=1;i<row;i++){
            for(int j=0,col=triangle[i].size();j<col;j++){

                if(j==0)
                    dp[i][j] = dp[i-1][j]+triangle[i][j];
                else if(j==col-1){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }else{
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j])+triangle[i][j];
                }
                if(i+1==row)
                    ans = min(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
```

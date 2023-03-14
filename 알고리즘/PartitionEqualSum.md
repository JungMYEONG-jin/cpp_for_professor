```c++
class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int n  = nums.size();
        int k = accumulate(nums.begin(), nums.end(), 0);
        if(k%2!=0)
            return false;
        k/=2;
        vector<vector<bool>> subsetSum = vector<vector<bool>>(k+1, vector<bool>(n+1, false));
        subsetSum[0][0] = true;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                if (nums[j-1]> i )
                {
                    subsetSum[i][j] = subsetSum[i][j-1];
                 }else{
                    subsetSum[i][j] = subsetSum[i-nums[j-1]][j-1] || subsetSum[i][j-1];
                 }
            
            }
        }
        return subsetSum[k][n];
    }
};
```

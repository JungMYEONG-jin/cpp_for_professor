```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long dp1[100001];
        long long dp2[100001];
        int len = nums.size();
        dp1[0] = nums[0];
        dp2[0] = nums[len-1];
        for(int i=1;i<len;i++){
            dp1[i] = nums[i] * dp1[i-1];
            dp2[i] = nums[len-i-1] * dp2[i-1]; 
        }

        for(int i=0;i<len;i++){
            cout<<dp1[i-1>=0?i-1:0]<<endl;
            cout<<dp2[len-i-2>=0?len-i-2:0]<<endl;
        }

        vector<int> result;
        for(int i=0;i<len;i++){
            if(i==0){
                result.push_back(dp2[len-2]);
            }else if(i==len-1){
                result.push_back(dp1[i-1]);
            }else{
                result.push_back(dp1[i-1] * dp2[len-i-2]);
            }
        }

        return result;
    }
};
```

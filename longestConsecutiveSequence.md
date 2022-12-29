## 가장 긴 연속 수열 길이 구하기

```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int cnt = 1;
        int maxLen = 0;
        for(int i=0, len = nums.size();i<len-1;i++){
            if(nums[i+1]==nums[i]+1){
                cnt++;
            }else if(nums[i+1]==nums[i])
                continue;
            else{
                maxLen = max(maxLen, cnt);
                cnt=1;
            }
        }
        maxLen = max(maxLen, cnt);
        return maxLen;
    }
};
```

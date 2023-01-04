##  Minimum Size Subarray Sum

슬라이딩 윈도우 기법으로 해결이 가능하다.
우선 커지는 순간을 구하고 나서 값을 계속 빼며 최소 길이를 구한다!

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int len = INT_MAX;
        int val = 0;
        for(int start=0, end=0;end<n;end++){
            val+=nums[end];
            while(val>=target){
                len = min(len, end-start+1);
                val-=nums[start++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }

};
```

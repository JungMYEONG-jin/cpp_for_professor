```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int cnt = 0;
        int major = 0;
        for(int i=0;i<len;i++){
            int temp = 1;
            int val = nums[i];
            while(i+1<len && val==nums[i+1])
            {
                i++;
                temp++;
            }
            if(cnt<temp){
                cnt = temp;
                major = val;
            }
        }
        return major;
    }
};
```

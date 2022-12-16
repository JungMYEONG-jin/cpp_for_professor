index 0 아닌것부터 채우기



```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        int len = nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]!=0)
                nums[idx++] = nums[i];
        }
        while(idx<len)
        {
            nums[idx++] = 0;
        }
    }
};
```

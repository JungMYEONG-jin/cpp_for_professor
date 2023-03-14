```c++
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort
    sort(nums.begin(), nums.end());
    int len = nums.size();
    for(int i = 0; i<len-2;i++){
        // check dup
        if(i>0 && nums[i] == nums[i-1])
            continue;
        int idx = i;
        int left = i+1;
        int right = len-1;
        while(left<right){
            int sum = nums[idx] + nums[left] + nums[right];
            if(sum==0){
                res.push_back({nums[idx], nums[left++], nums[right--]});
                // check dup
                while(left<right && nums[left] == nums[left-1])
                    left++;
            }else if(sum>0)
            {
                right--;
            }else if(sum<0){
                left++;
            }
        }
    }



    return res;
    }
};
```

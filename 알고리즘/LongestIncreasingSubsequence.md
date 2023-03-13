```c++
class Solution {
public:
    int binary(vector<int>& res, int start, int end, int val){
    while(start<end){
        int mid = (start+end)>>1;
        if(val > res[mid])
            start = mid + 1;
        else
            end = mid;
    }
    return end;
}

int lengthOfLIS(vector<int>& nums) {
    int ans = 0;
    vector<int> res;
    res.push_back(nums[0]);
    int len = nums.size();
    for(int i=1;i<len;i++){
        if(nums[i]>res.back()){
            res.push_back(nums[i]);
            ans = res.size() - 1;
        }
        int pos = binary(res, 0, ans, nums[i]);
        res[pos] = nums[i];
    }      
    return ans+1;
}
};
```

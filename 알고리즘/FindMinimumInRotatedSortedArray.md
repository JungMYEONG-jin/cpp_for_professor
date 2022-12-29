## Binary Search

이분 탐색을 이용해 제일 작은 원소 찾기

```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left<right){
            int mid = (left+right)>>1;
            if(nums[mid]>nums[right])
            {
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return nums[right];
    }
};
```

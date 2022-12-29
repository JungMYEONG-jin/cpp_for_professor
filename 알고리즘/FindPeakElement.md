## Binary Search

mid를 구한후 오른쪽과 비교를 진행한다. 만약 오른쪽이 더 크면 left = mid+1로 변경해주고 오른쪽이 더 작으면 right = mid 로 변경해주면서

마지막 left를 넘겨주면 끝난다.

```c++
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int len = nums.size();
        int right = len-1;
        while(left<right){
            int mid = (left+right)>>1;
            if(nums[mid]<nums[mid+1]){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
```

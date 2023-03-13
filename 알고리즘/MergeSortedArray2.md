```c++
#include <queue>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int k = m+n-1;
    int lidx = m-1;
    int ridx = n-1;
    // 이미 정렬이 된  상태니까
    while(lidx>=0 && ridx>=0){
        if(nums1[lidx]>nums2[ridx]){
            nums1[k] = nums1[lidx];
            k--;
            lidx--;
        }else{
            nums1[k] = nums2[ridx];
            k--;
            ridx--;
        }
    }
    while(ridx>=0){
        nums1[k--] = nums2[ridx--];
    }
    }
};
```

```c++
#include <queue>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int lidx = 0;
    int ridx = 0;
    int len = nums1.size();
    if(n==0)
        return;
    if(m==0)
    {
        for(int i=0;i<len;i++)
            nums1[i] = nums2[i];
        return;
    }
    queue<int> q;
    while(lidx<m && ridx<n){
        if(nums1[lidx]<nums2[ridx]){
            q.push(nums1[lidx++]);
        }else
            q.push(nums2[ridx++]);
    }

    while(lidx<m){
        q.push(nums1[lidx++]);
    }

    while(ridx<n){
        q.push(nums2[ridx++]);
    }

    int qsize = q.size();
    for(int i=0;i<qsize;i++){
        nums1[i] = q.front();
        q.pop();
    }
    }
};
```

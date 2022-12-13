## leetcode 1일차


```c++
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    long firstBadVersion(long n) {
        long left = 1;
        long right = n+1;
        long prev = n;
        while(left<=right){
            long mid = (left+right)>>1;
            if(!isBadVersion(mid))
                left = mid+1;
            else
            {
                prev = mid;
                right = mid-1;
            }
        }
        return prev;
    }
};
```

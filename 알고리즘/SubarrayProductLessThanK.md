## Sliding Window

각 인덱스에서 부터 시작해서 계속 꾸준히 곱해준다. 만약 값이 작다면 그 길이만큼 더해주고 값이 커지는 순간 left를 옮기며 값을 현재 값을 나눠 다시 K보다 작아질때까지 이동한다.
O(n) 안에 해결이 가능하다.

```c++
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        long long val = 1;
        int len = 0;
        for(int start=0, end=0;end<n;end++){
            val*=nums[end];

            while(val>=k && start<end){
                val/=nums[start++];
            }

            if(val<k)
            {
                int result = end-start+1;
                len+=result;
            }
        }
        return len;
    }
};
```

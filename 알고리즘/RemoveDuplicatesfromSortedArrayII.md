## leetcode 중복 제거하기

O(N)으로 해결

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dupCnt = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                dupCnt++;
                if(dupCnt>1){
                    nums.erase(nums.begin()+i);
                    i--;
                }
            }else
                dupCnt=0;

        }
        return nums.size();
    }
};
```

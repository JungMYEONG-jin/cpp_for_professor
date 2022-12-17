## 투포인터로 타겟 구하기. 요즘 투포인터가 많이 나오네


```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        while(left<right){
            int val = numbers[left]+numbers[right];
            if(val>target){
                right--;
            }else if(val<target){
                left++;
            }else{
                return {left+1, right+1};
                break;
            }
        }
        return {1, 2};
    }
};
```

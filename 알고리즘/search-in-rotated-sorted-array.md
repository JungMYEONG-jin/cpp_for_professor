## Binary Search

k 피봇만큼 움직여 타겟을 찾을 수 있느지 찾는 문제이다. 문제 설명은 그럴싸 해보이지만 사실 그냥 target의 index만 찾으면 끝이다.

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = find(nums.begin(), nums.end(), target);
        if(it==nums.end())
            return -1;
        return it-nums.begin();
    }
};
```

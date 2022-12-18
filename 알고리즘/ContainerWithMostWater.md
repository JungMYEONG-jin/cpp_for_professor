## 투포인터로 구하기

각 빌딩의 높이를 비교하면서 최대 넓이를 계속 갱신하자


```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int len = height.size();
        int right = len-1;
        int maxWater = 0;
        while(left<right){
            int val = min(height[left], height[right]);
            maxWater = max(maxWater, val * (right-left));
            if(height[right]>height[left])
                left++;
            else
                right--;
        }
        return maxWater;
    }
};
```

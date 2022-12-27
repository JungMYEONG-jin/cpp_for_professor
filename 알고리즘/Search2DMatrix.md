## BinarySearch

각 로우마다 정렬된 상태이므로 for를 돌며 binary search 진행

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto it : matrix){
            auto idx = binary_search(it.begin(), it.end(), target);
            if(idx){
                return true;
            }
        }
        return false;
    }
};
```

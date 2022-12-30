## Two Pointer

투포인터를 이용해 겹치는 구간 찾기.

```c++
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int n = firstList.size();
        int m = secondList.size();
        int i = 0;
        int j = 0;
        while((i<n) && (j<m)){
            int left = max(firstList[i][0], secondList[j][0]);
            int right = min(firstList[i][1], secondList[j][1]);
            if(left<=right){
                res.push_back({left, right});
            }
            if(firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
        }
        return res;
    }
};
```

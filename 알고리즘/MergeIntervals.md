## merge interval


```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto it, auto it2){
            return it[0]<it2[0];
        });
        int idx = 0;
        for(int i=1, len = intervals.size();i<len;i++){
            auto it2 = intervals[i];
            if(it2[0]<=intervals[idx][1]){
                intervals[idx][1] = max(it2[1], intervals[idx][1]);
            }else{
                idx++;
                intervals[idx] = it2;
            }
        }
        return vector<vector<int>>(intervals.begin(), intervals.begin()+idx+1);
    }
};

```

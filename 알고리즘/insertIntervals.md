## 시작점 기준 정렬하고 idx의 끝과 구간의 시작점을 비교하면서 순회



```c++
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size();
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(),[](auto it, auto it2){return it[0]<it2[0];});
        int idx = 0;
        for(int i=1;i<=n;i++){
            auto it = intervals[i];
            if(intervals[idx][1]>=it[0]){
                // 만약 intervals end가 더크면
                intervals[idx][1] = max(intervals[idx][1], it[1]);
            }else{
                idx++;
                intervals[idx] = it;
            }
        }
        return vector<vector<int>>(intervals.begin(), intervals.begin()+idx+1);

    }
};

```

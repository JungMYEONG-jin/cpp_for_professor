## Backtracking

백트래킹과 사고능력이 필요. 우선 정렬후 set에 넣으면서 마지막은 set을 vector로 변환하면됨

```c++
class Solution {
public:

    vector<vector<int>> res;
    set<vector<int>> resSet;
    bool visited[11];

    void subset(vector<int>& nums, vector<int>& temp, int idx){
        resSet.insert(temp);
        for(int i=idx,n = nums.size();i<n;i++){
            temp.push_back(nums[i]);
            subset(nums, temp, i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        sort(nums.begin(), nums.end());
        subset(nums, temp, 0);
        for(auto& it : resSet)
            res.push_back(it);
        return res;
    }
};
```

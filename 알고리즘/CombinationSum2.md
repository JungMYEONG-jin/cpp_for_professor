그냥 combinationSum과 비슷하지만 자신을 무제한 여러번 사용 못한다. 따라서 중복체크가 필요함.



```c++
class Solution {
public:
    vector<vector<int>> res;

    void backTrack(vector<int>& candidates, int idx, int target, vector<int>& temp){
        if(target==0)
        {
            res.push_back(temp);
            return;
        }
        for(int i=idx, len = candidates.size();i<len;i++){
            if(i>idx && candidates[i]==candidates[i-1])
                continue;
            if(target-candidates[i]<0)
                return;
            temp.push_back(candidates[i]);
            backTrack(candidates, i+1, target-candidates[i], temp);
            temp.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        backTrack(candidates, 0, target, temp);
        return res;
    }
};
```

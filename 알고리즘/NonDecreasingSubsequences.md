## 감소하지 않는 부분 집합 구하기

백트래킹으로 해결

```c++
class Solution {
public:

    set<vector<int>> res;
    void combi(int idx, int len, vector<int>& temp, vector<int>& nums){
        if(temp.size()>1){
            res.insert(temp);
        }
        
        for(int i=idx;i<len;i++){
            if(temp.empty() || (temp.back()<=nums[i])){
                temp.push_back(nums[i]);
                combi(i+1, len, temp, nums);
                temp.pop_back();
                
            }
        }
    }


    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int len = nums.size();
        vector<int> temp;
        combi(0, len, temp, nums); 
        return vector<vector<int>>(res.begin(), res.end());
    }
};
```

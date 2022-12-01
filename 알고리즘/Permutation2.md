# STL
직접 구현할 수도 있고 간단하게 STL을 사용할 수 있다. 저번에 직접 구현으로 풀어서 이번엔 STL로 해봤음

```c++
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back(nums);
        while(next_permutation(nums.begin(), nums.end())){
            res.push_back(nums);
        }
        return res;
    }
};

```

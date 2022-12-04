LEET CODE  부분 집합 구하기
방문을 나타내서 중복을 


```c++
class Solution {
public:

    vector<vector<int>> res;
    bool visited[11];

    void subset(int n, int depth, vector<int>& nums, vector<int>& temp)
    {
        if(n==depth){
            res.push_back(temp);
            return;
        }
        visited[depth] = false;
        temp.push_back(nums[depth]);
        subset(n, depth+1, nums, temp);
        visited[depth] = true;
        temp.pop_back();
        subset(n, depth+1, nums, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        subset(n, 0, nums, temp);
        return res;
    }
};

```

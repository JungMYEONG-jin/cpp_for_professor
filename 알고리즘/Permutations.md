## 순열 구현하기

```c++
class Solution {
public:
    
   vector<vector<int>> res;
   bool visited[7];

void dfs(vector<int>& nums, vector<int>& temp, int cnt) {
    if(cnt==nums.size()){
        res.push_back(temp);
        return;
    }
    for(int i=0, len = nums.size();i<len;i++){
        if(!visited[i]){
            visited[i] = true;
            temp.push_back(nums[i]);
            dfs(nums, temp, cnt+1);
            temp.pop_back();
            visited[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<int> temp;
    dfs(nums, temp, 0);
    return res;
}
};
```

```c++
class Solution {
public:

    void dfs(string s, int idx, vector<string> temp, vector<vector<string>>& res){
        if(idx == s.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isValid(s, idx, i)){
                temp.push_back(s.substr(idx, i-idx+1));
                dfs(s, i+1, temp, res);
                temp.pop_back();
            }
        }
    }

    bool isValid(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        dfs(s, 0, temp, res);
        return res;
    }
};
```

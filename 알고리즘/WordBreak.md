```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 순서대로 찾아
        int len = s.size();
        bool dp[301];
        
        fill(dp, dp+301, false);
        dp[0] = true;
        for(int i=0;i<=len;i++){
            for(string word : wordDict){
                if(i<word.size())
                    continue;
                cout<< s.substr(i-word.size(), word.size())<<endl;
                if(dp[i-word.size()] && s.substr(i-word.size(), word.size()) == word){
                    dp[i] = true;
                }
            }
        }
        return dp[len];
    }
};
```

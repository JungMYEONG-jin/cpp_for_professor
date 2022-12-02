큐를 이용한 dfs


```c++
class Solution {
public:

    vector<string> letter(string digits, int n, map<char, string>& db){
        vector<string> res;

        queue<string> q;
        q.push("");
        while(!q.empty()){
            string s = q.front();
            q.pop();
            if(s.length()==n)
                res.push_back(s);
            else{
                for(auto it : db[digits[s.length()]])
                    q.push(s+it);
            }
        }
        return res;
    }
    


    vector<string> letterCombinations(string digits) {
        map<char, string> db;
        if(digits.empty())
            return {};
        db['2'] = "abc";
        db['3'] = "def";
        db['4'] = "ghi";
        db['5'] = "jkl";
        db['6'] = "mno";
        db['7'] = "pqrs";
        db['8'] = "tuv";
        db['9'] = "wxyz";
        return letter(digits, digits.size(), db);
    }
};
```

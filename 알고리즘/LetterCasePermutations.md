## DFS

```c++
class Solution {
public:

    vector<string> res;
    void permutation(string s, string result){
        if(s.size()==0)
        {
            res.push_back(result);
            return;
        }
        char ch = s[0];
        char low = tolower(ch);
        char upper = toupper(ch);

        s = s.substr(1);
        if(!isdigit(ch))
        {
            permutation(s, result+low);
            permutation(s, result+upper);
        }else
            permutation(s, result+ch);
    }

    vector<string> letterCasePermutation(string s) {
        string temp = "";
        permutation(s, temp);
        return res;
    }
};
```

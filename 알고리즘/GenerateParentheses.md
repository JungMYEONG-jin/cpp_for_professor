## 백트래킹

```c++
class Solution {
public:

    vector<string> res;

    void generate(string temp, int left, int right, int n){
        if(temp.size() == 2*n){
            res.push_back(temp);
            return;
        }
        if(left<n)
        {
            temp+="(";
            generate(temp, left+1, right, n);
            temp.pop_back();
        }
        if(right<left){
            temp+=")";
            generate(temp, left, right+1, n);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        generate("", 0, 0, n);
        return res;
    }
};
```

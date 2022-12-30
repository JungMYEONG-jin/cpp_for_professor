## Two Pointer

간단한 구현 문제.

```c++
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string left = "";
        string right = "";
        for(auto i : s){
            if(i!='#')
                left.push_back(i);
            else if(!left.empty() && i=='#')
                left.pop_back();
        }

        for(auto i : t){
            if(i!='#')
                right.push_back(i);
            else if(!right.empty() && i=='#')
                right.pop_back();
        }

        return left == right;
    }
};
```

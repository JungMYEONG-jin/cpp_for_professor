# string 변환후 reverse해서 일치여부 비교

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        string res = to_string(x);
        string temp = res;
        reverse(temp.begin(), temp.end());
        return res == temp;
            
        }
};
```

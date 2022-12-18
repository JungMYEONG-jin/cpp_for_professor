## STL 이용한 find

```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle)!=haystack.npos)
            return haystack.find(needle);
        return -1;
    }
};
```

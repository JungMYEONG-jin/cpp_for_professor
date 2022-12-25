## Bitwise

bitwise 또는 구현으로 풀면됨.

```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
      if(n<=0)
        return false;
    return (n&(n-1))==0;
    }
};
```

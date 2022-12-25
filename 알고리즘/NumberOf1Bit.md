## Bitwise

bitwise로 풀수도 있고 STL로도 가능. 

```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> res(n);
        return res.count();
    }
  
    int hammingWeight(uint32_t n) {
      int cant=0;
      while(n){
        if(n&1){
        cant++;
      }
      n=n>>1;
    }   
    return cant;
  }
  
};
```

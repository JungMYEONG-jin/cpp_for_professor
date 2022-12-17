## ReveseString 문제. extra space를 O(1)만 써야 해서 추가로 배열 만들면 안됨. 그래서 투포인터로 해결


```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size()-1;
        while(left<=right){
            char prev = s[left];
            s[left] = s[right];
            s[right] = prev;
            left++;
            right--;
        }
    }
};
```

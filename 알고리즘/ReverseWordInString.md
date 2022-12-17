## Stringstream으로 공백 기준 분리해서 리버스 후 합쳐줌. O(N)으로 예상

```c++
class Solution {
public:
    string reverseWords(string s) {
        stringstream sstr(s);
        string temp = "";
        string ans;
        while(getline(sstr, temp, ' ')){
            int left = 0;
            int right = temp.size()-1;
            while(left<=right){
                char c = temp[left];
                temp[left] = temp[right];
                temp[right] = c;
                left++;
                right--;
            }
            ans+=temp+" ";
        }
        ans.pop_back();
        return ans;
    }
};
```

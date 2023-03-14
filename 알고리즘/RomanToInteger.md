```c++
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman;
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    int num = 0;
    int prev = 0;
    for(char ch : s){
        if(prev>=roman[ch]){
             num += roman[ch];
        }else{
            num -= 2 * prev;
            num += roman[ch];
        }
        prev = roman[ch];
    }
    return num;
    }
};
```

## 간단한 구현

간단한 구현 문제인듯?

```c++
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman{ {1,"I"}, {4, "IV"}, {5, "V"},{9, "IX"}, {10,"X"}, {40, "XL"}, {50,"L"},{90,"XC"}, {100, "C"},{400, "CD"}, {500,"D"}, {900, "CM"}, {1000, "M"} };
	reverse(roman.begin(), roman.end());
	string str = "";
        for(const auto& it : roman){
            while(num>=it.first)
            {
                str+=it.second;
                num-=it.first;
            }
        }
        return str;
    }
};
```

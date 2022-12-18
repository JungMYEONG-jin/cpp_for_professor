## string permutation을 진짜 전부 돌리면 시간 초과가 난다.

우선 s1 의 카운트를 저장하고 해당 카운트 기준 s2에서 비교한다.길이가 s1


```c++
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1>len2)
            return false;
        int dp[26] = {0};
        for(auto ch : s1)
            dp[ch-'a']++; // count
        
        auto isValid = [](int arr[], int len){
            for(int i=0;i<len;i++)
            {
                if(arr[i]!=0)
                    return false;
            }
            return true;
        };

        for(int i=0;i<len2;i++){
            dp[s2[i]-'a']--;
            if(i>=len1){
                dp[s2[i-len1]-'a']++; // 이전 원소 다시 증가
            }
            if(isValid(dp, 26))
                return true;
        }
        return false;
        
    }
};
```

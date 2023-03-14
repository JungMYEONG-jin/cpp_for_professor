```c++
class Solution {
public:
    int lcs[1001][1001] = {0,};

    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty() || text2.empty())
        return 0;
        int longest = 0;
        int len1 = text1.size();
        int len2 = text2.size();

        for(int i=1;i<=len2;i++){
            for(int j=1;j<=len1;j++){
                if(text2[i-1] == text1[j-1]){
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                }else{
                    if (lcs[i-1][j] > lcs[i][j-1])
                    {
                    /* code */
                        lcs[i][j] = lcs[i-1][j];
                    }else{
                        lcs[i][j] = lcs[i][j-1];
                    }
                
                }

                longest = max(longest, lcs[i][j]);
            }
        }
    return longest;
    }
};
```

## 슬라이딩 윈도우 기법으로 중복되는 문자가 없는 가장 긴 문자열 구하기

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len = s.size();
        if(len<=1)
            return len;
        int idx = 0;
        int maxLen = 0;

        for(int i=0;i<len-1;i++){
            int j = i+1;
            idx = i;
            map<char, bool> db;
            db[s[idx]] = true;
            while(db.find(s[j])==db.end() && j<len)
            {
                db[s[j]] = true;
                j++;
            }
            maxLen = max(maxLen, j-i);
        }


        return maxLen;

    }
};
```

# GeeksForGeeks의 풀이

방문한 인덱스를 

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len = s.size();
        if(len<=1)
            return len;
        map<char, int> db; // char idx
        int start = 0;
        int maxLen = 0;
        for(int i=0;i<len;i++){

            // check if visited before
            if(db.find(s[i])!=db.end()){
                start = max(start, db[s[i]]+1);
            }
            db[s[i]] = i;
            maxLen = max(maxLen, i-start+1);
        }


        return maxLen;

    }
};
```
```

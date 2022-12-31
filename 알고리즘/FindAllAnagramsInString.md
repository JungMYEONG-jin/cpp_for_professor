## Sliding Window

처음에 2중 반복으로 했다가 시간 초과남..

길이가 비교 문자열보다 길어지면 다시 인덱스 더해서 설정하면서 O(n)으로 해결함

```c++
class Solution {
public:
    bool isValid(map<char, int>& db){
        for(auto& it : db)
        {
            if(it.second!=0)
                return false;
        }
        return true;
    }


    vector<int> findAnagrams(string s, string p) {
        map<char, int> db;
        vector<int> ans;
        for(auto i : p)
            db[i]++;

        
        int plen = p.size();
        int slen = s.size();

        int idx = 0;
        for(int i=0;i<slen;i++){
            db[s[i]]--;
            if(i-idx>=plen)
                db[s[idx++]]++;
            if(isValid(db))
                ans.push_back(idx);
        }  
        return ans;
    }
};
```

자료구조를 사용해야 빨리 해결 가능.
그냥 for문 돌리면 시간초과!


```c++
class Solution {
public:
    vector<vector<string>> res;
   
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> db;
        int cnt = 0;
        for(int i=0, len=strs.size();i<len;i++){
            string key = strs[i];
            sort(key.begin(), key.end());
            if(db.find(key)!=db.end()){
                int idx = db[key];
                res[idx].push_back(strs[i]);
            }else{
                db[key] = cnt++;
                vector<string> temp;
                temp.push_back(strs[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
};


```

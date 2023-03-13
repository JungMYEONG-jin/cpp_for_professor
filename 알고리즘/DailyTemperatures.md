```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int len = temperatures.size();
        vector<int> res(len);
        for(int i=0;i<len;i++){
            while(!s.empty() && temperatures[s.top()]<temperatures[i]){
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            res[s.top()] = 0;
            s.pop();
        }      
        return res; 
    }
};
```

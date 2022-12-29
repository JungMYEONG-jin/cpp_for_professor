## 로직 구현

정렬후 로직대로 구현

```c++
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
       
        int len = tasks.size();
        int i = 0;
        long time = 0;
        for(int i=0;i<len;i++)
            tasks[i].push_back(i); // add index
        vector<int> ans;
        sort(tasks.begin(), tasks.end()); // start time sort
        // start cost index
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        while(i<len || !pq.empty()){
            if(pq.empty())
                time = max(time, static_cast<long>(tasks[i][0])); // 시작 시간
            while(i<len && time>=tasks[i][0]){
                pq.push({tasks[i][1], tasks[i][2]});
                ++i;
            }
            auto it = pq.top();
            pq.pop();
            time+=it.first;
            ans.push_back(it.second);
        }

        return ans;
    }
};
```

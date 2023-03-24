```c++
class Solution {
public:
  
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> pre(numCourses, 0);
        for(const auto& it : prerequisites){
            graph[it[1]].push_back(it[0]);
            pre[it[0]]++;
        }
        int n = numCourses;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(pre[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int next : graph[cur]){
                pre[next]--;
                if(pre[next] == 0){
                    q.push(next);
                }

            }

            n--;
        }
        return n==0;
    }
};
```

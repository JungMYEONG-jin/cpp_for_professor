```c++
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& path, vector<bool>& visited){
        if(visited[node])
            return false;
        path[node] = visited[node] = true;
        for(int next : graph[node]){
            if(path[next] || dfs(next, graph, path, visited))
                return true;
        }
        return path[node] = false;
    }
    

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> path = visited;
        for(const auto& it : prerequisites){
            graph[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs(i, graph, path, visited))
                return false;
        
        return true;
    }
};
```

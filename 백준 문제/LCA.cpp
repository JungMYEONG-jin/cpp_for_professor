#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

bool visited[50001];
int depth[50001];
int parent[50001];
vector<int> graph[50001];

int lca(int x, int y){
    if(depth[x] > depth[y]){
        swap(x, y);
    }

    while(depth[x] != depth[y]){
        y = parent[y];
    }

    while(x != y){
        x = parent[x];
        y = parent[y];
    }
    return x;
}


int main()
{
    int t, n, x, y;
  
    cin>>n;

    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }



    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int next : graph[cur]){
            if(!visited[next]){
                parent[next] = cur;
                depth[next] = depth[cur]+1;
                visited[next] = true;
                q.push(next);
            }
        }
    }


    cin>>t;
    for(int i=0;i<t;i++){
        cin>>x>>y;
        cout<<lca(x, y)<<'\n';
    }
        
        

    return 0;

}

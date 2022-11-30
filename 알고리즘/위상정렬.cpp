#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;

vector<vector<int> > adj;
vector<int> indegree;
vector<bool> visited;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    adj.resize(N+1);
    indegree.resize(N+1);
    int a, b;
    for(int i=1;i<=M;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
        
    }
    
    
    priority_queue<int, vector<int>, greater<int>> res;
    for(int i=1;i<=N;i++)
    {
        if(indegree[i]==0)
            res.push(i);
    }
    
    while(!res.empty())
    {
        int k = res.top();
        res.pop();
        cout<<k<<" ";
        
        for(int i=0;i<adj[k].size();i++)
        {
            int val = adj[k][i];
            indegree[val]--;
            if(indegree[val]==0)
                res.push(val);
        }
        
        
    }
    
    
    return 0;
}

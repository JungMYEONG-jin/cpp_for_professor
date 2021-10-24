#include <iostream>
#include <queue>

using namespace std;

bool visited[100001];
queue<pair<int, int>> q;
int result, k;

bool is_valid(int n)
{
    if(n<0 || n>100000 || visited[n])
        return false;
    return true;
}

void dfs(int n)
{
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x==k)
        {
            result = y;
            return;
        }
        if(is_valid(x-1))
        {
            q.push({x-1, y+1});
            visited[x-1]=true;
        }
        if(is_valid(x+1))
        {
            q.push({x+1, y+1});
            visited[x+1]=true;
        }
        if(is_valid(2*x))
        {
            q.push({2*x, y+1});
            visited[2*x]=true;
        }
    }
    return;
}

int main()
{
    int n;
    cin>>n>>k;
    visited[n] = true;
    q.push({n,0});
    dfs(n);
    cout<<result<<endl;
}

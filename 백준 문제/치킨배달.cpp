#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> house, store, temp;
int ans, n, m, chicken;
bool visited[13];
int get_dist();
void dfs(int idx, int cnt)
{
    if(cnt==m)
    {
        ans = min(ans, get_dist());
        return;
    }
    
    for(int i = idx;i<chicken;i++)
    {
        if(visited[i])
            continue;
        visited[i] = true;
        temp.push_back(store[i]);
        dfs(i, cnt+1);
        visited[i] = false;
        temp.pop_back();
    }
}


int get_dist()
{
    int sum = 0;
    for(auto& i : house)
    {
        int d = 999999999;
        for(auto& j : temp)
        {
            d = min(d, abs(i.first-j.first)+abs(i.second-j.second));
        }
        sum+=d;
    }
    return sum;
}



int main()
{
    
    cin>>n>>m;
    vector<vector<int>> res(n+1, vector<int>(n+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>res[i][j];
            if(res[i][j]==2)
                store.push_back({i,j});
            else if(res[i][j]==1)
                house.push_back({i,j});
        }
    }
    ans = 999999999;
    chicken = store.size();
    dfs(0,0);
    cout<<ans<<endl;
    
    
    
}

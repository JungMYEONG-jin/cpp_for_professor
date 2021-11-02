#include <iostream>
#include <queue>

using namespace std;

int db[101];
bool visited[101];

int main()
{
    int n, m;
    cin>>n>>m;
    int result = 0;
    for(int i=1;i<=100;i++)
        db[i]=i;
    int x, y;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        db[x]=y;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        db[x] = y;
    }
    
    visited[1] = true;
    queue<pair<int, int>> q;
    q.push({1, 0});
    
    while(!q.empty())
    {
        int dice = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(dice>=100)
        {
            result = dist;
            break;
        }
        for(int i=1;i<=6;i++)
        {
            int ndice = dice+i;
            if(ndice>100)
                continue;
            ndice = db[ndice];
            if(!visited[ndice])
            {
                visited[ndice] = true;
                q.push({ndice, dist+1});
            }
        }
    }
    cout<<result<<endl;
    
}

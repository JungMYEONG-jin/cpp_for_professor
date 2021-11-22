#include <vector>
#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int db[50][50];
int visited[50][50];
bool selected[10];
int n,m;
vector<pair<int, int>> virus;
vector<pair<int, int>> vs;
int ans;
int emp;
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};



void virus_move()
{
   queue<pair<int, int>> q;
   for(auto& it : vs)
   {
       q.push(it);
       visited[it.first][it.second]=0;
   }
   int num=0;
   int cnt = 0;
   while(!q.empty())
   {
         int x = q.front().first;
         int y = q.front().second;
         q.pop();
         for(int i=0;i<4;i++)
         {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n)
            {
               if(visited[nx][ny]==-1 && db[nx][ny]!=1)
               {
                  visited[nx][ny] = visited[x][y]+1;
                  if(db[nx][ny]==0)
                  {
                     cnt++;
                     num = visited[nx][ny];
                  }
                  q.push({nx,ny});
               }
            }
         }
      }
    
    if(cnt==emp)
      ans = min(ans, num);
   }


void bfs(int idx, int cnt)
{
   if(cnt==m)
   {
      memset(visited, -1, sizeof(visited));
      virus_move();
      return;
   }

   for(int i=idx, len = virus.size();i<len;i++)
   {
      if(selected[i])
         continue;
      selected[i] = true;
      vs.push_back(virus[i]);
      bfs(i, cnt+1);
      vs.pop_back();
      selected[i] = false;
   }
}



int main()
{
	cin>>n>>m;
   int cnt = 0;
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
         cin>>db[i][j];
         if(db[i][j]==2)
            virus.push_back({i,j});
         if(db[i][j]==0)
            emp++;
      }
   }
   ans = 999999999;
   bfs(0,0);
   if(ans==999999999)
      cout<<-1<<endl;
   else
      cout<<ans<<endl;


}

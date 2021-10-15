#include <vector>
#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int db[50][50];
bool visited[50][50];
bool selected[10];
int n,m;
vector<pair<int, int>> virus;
vector<pair<int, int>> vs;
int ans;

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

bool check()
{
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
         if(db[i][j]==1)
            continue;
         if(visited[i][j]==false)
            return false;
      }
   }
   return true; // 전부다찬경우
}

void virus_move()
{
   queue<pair<int, int>> q;
   for(auto& it : vs)
   {
       q.push(it);
       visited[it.first][it.second]=true;
   }
   int num=0;
   while(!q.empty())
   {
      
      int len = q.size();
      for(int i=0;i<len;i++)
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
               if(visited[nx][ny]==false && db[nx][ny]!=1)
               {
                  visited[nx][ny] = true;
                  q.push({nx,ny});
               }
            }
         }
      }
      if(!q.empty())
         num++;
   }
   if(check())
      ans = min(ans, num);
   return;

}


void bfs(int idx, int cnt)
{
   if(cnt==m)
   {
      memset(visited, false, sizeof(visited));
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
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
         cin>>db[i][j];
         if(db[i][j]==2)
            virus.push_back({i,j});
      }
   }
   ans = 999999999;
   bfs(0,0);
   if(ans==999999999)
      cout<<-1<<endl;
   else
      cout<<ans<<endl;


}

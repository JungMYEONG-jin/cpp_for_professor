#include <vector>
#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>
#include <tuple>
#include <set>
#include <map>
#include <string>

#define INF 9999
using namespace std;

int a, b, c;
int dz[] = {1,-1,0,0,0,0};
int dx[] = {1,-1,0,0};
int dy[] = {0, 0, 1, -1};

vector<pair<int, int>> graph[11];
vector<tuple<int, int, int>> bridge; // a to b cost c
int total;
int db[10][10];
int label[10][10];
bool visited[10][10];
int n, m;
int ans = INF;
int dist[7][7];
bool con[7][7];
bool conland[7];
bool selected[49];

void make_land(int x, int y, int num)
{
   visited[x][y] = true;
   label[x][y] = num;
   queue<pair<int, int>> q;
   q.push({x, y});
   graph[num].push_back({x,y});
   while(!q.empty())
   {
      auto it = q.front();
      q.pop();
      int xx = it.first;
      int yy = it.second;
      for(int i=0;i<4;i++)
      {
         int nx = xx+dx[i];
         int ny = yy+dy[i];

         if(nx>=0&&ny>=0&&nx<n&&ny<m)
         {
            if(!visited[nx][ny] && db[nx][ny]==1)
            {
               visited[nx][ny] = true;
               q.push({nx, ny});
               graph[num].push_back({nx, ny});
               label[nx][ny] = num;
            }
         }
      }
   }
}

void dfs(int x, int y, int dir, int bsize, int start, int end)
{
   int nx = x+dx[dir];
   int ny = y+dy[dir];
   if(nx<0 || ny<0 || nx>=n || ny>=m)
      return;
   if(db[nx][ny]==0)
      dfs(nx, ny, dir, bsize+1, start, end);
   else if(db[nx][ny]==1)
   {
      if(label[nx][ny]==end)
      {
         if(bsize>1)
         {
            if(dist[start][end]>bsize)
            {
               dist[start][end] = bsize;
               dist[end][start] = bsize;
            }
            return;
         }
      }else
         return;
   }
  

}

void make_bridge(int start, int end) // start island end island
{
   for(auto it : graph[start])
   {
      int x = it.first;
      int y = it.second;
      
      for(int i=0;i<4;i++)
      {
         int nx = x+dx[i];
         int ny = y+dy[i];
         if(nx>=0 && ny>=0 && nx<n && ny<m)
         {
            if(db[nx][ny]==0) // 모든지점으로부터 거리구하기
               dfs(x, y, i, 0, start, end);
         }
      }
   }
}

bool check()
{
   memset(con, false, sizeof(con));
   memset(conland, false, sizeof(conland));

   for(int i=0, len = bridge.size();i<len;i++)
   {
      if(selected[i])
      {
         auto it = bridge[i];
         int x, y, cost;
         tie(x, y, cost) = it;
         con[x][y] = true;
         con[y][x] = true; // connected
      }
   }

   bool flag = false;
   queue<int> q;
   q.push(1); // check all the island connected
   conland[1] = true;

   int num = 1;

   while(!q.empty())
   {
      int cur = q.front();
      q.pop();

      if(num==total-1)
      {
         flag = true;
         break;
      }

      for(int i=1;i<total;i++)
      {
         if(cur==i)
            continue;
         if(con[cur][i] && !conland[i])
         {
            conland[i] = true;
            q.push(i);
            num++;
         }
      }

   }
   return flag;

}


void getdistance()
{
   for(int i=1;i<total;i++)
   {
      for(int j=i+1;j<total;j++)
      {
         make_bridge(i, j);
         if(dist[i][j]==INF)
            continue;
         bridge.push_back({i, j, dist[i][j]});
      }
   }
}

void Dist_Dfs(int idx, int cnt, int s)
{
   if(cnt>=1)
   {
      if(check())
      {
         ans = min(ans, s);
      }
   }

   for(int i=idx, len = bridge.size();i<len;i++)
   {
      if(selected[i])
         continue;
      selected[i] = true;
      Dist_Dfs(i, cnt+1, s+get<2>(bridge[i]));
      //cout<<get<2>(bridge[i]);
      selected[i] = false;
   }
}


int main()
{  
 
   // init dist
   for(int i=0;i<7;i++)
   {
      for(int j=0;j<7;j++)
         dist[i][j] = INF;
   }

   cin>>n>>m;
   vector<pair<int, int>> res;
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
         cin>>db[i][j];
         if(db[i][j]==1)
            res.push_back({i,j});
      }
   }

   int num = 1;
   for(int i=0, len = res.size();i<len;i++)
   {
      auto it = res[i];
      int x = it.first;
      int y= it.second;
      //cout<<x<<" "<<y<<endl;
      if(!visited[x][y])
      {
         make_land(x, y, num++);
      }
   }

   total = num;
   
   getdistance();
   Dist_Dfs(0, 0, 0);

   if(ans==INF)
      cout<<-1<<endl;
   else
      cout<<ans<<endl;


 
    
}





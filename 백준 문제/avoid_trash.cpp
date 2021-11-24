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

#define INF 999999999

using namespace std;

int n, m;

int dx[4] = {1,-1,0,0};
int dy[4] = {0, 0, 1, -1};

int db[101][101];
bool visited[101][101];



int main()
{
   int t;
   cin>>n>>m>>t;
   memset(db, 0, sizeof(db));
   int x, y;
   vector<pair<int, int>> trash;
   for(int i=0;i<t;i++)
   {
      cin>>x>>y;
      db[x][y]=1;
      trash.push_back({x, y});
   }

   int ans = 0;

   for(const auto& it : trash)
   {
      int sz = 0;
      if(!visited[it.first][it.second]) // 방문 안한것만 탐색
      {
         queue<pair<int, int>> q;
         q.push({it.first, it.second});
         visited[it.first][it.second] = true;
         while(!q.empty())
         {
            auto it2 = q.front();
            q.pop();
            int x = it2.first;
            int y = it2.second;
            sz++;
            for(int i=0;i<4;i++)
            {
               int nx = x+dx[i];
               int ny = y+dy[i];

               if(nx>0 && ny>0 && nx<=n && ny<=m)
               {
                  if(!visited[nx][ny] && db[nx][ny]==1)
                  {
                     visited[nx][ny]=true;
                     q.push({nx, ny});
                  }
               }
            }
         }
         ans = max(ans, sz);
      }
   }

   cout<<ans;

    
}





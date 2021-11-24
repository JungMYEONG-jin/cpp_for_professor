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
int db[101][101];
int visited[101][101];
int air[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0, 0, 1, -1};

void spread()
{
   queue<pair<int, int>> q;
   q.push({0,0});
   while(!q.empty())
   {
      auto it = q.front();
      q.pop();
      int x = it.first;
      int y = it.second;
      if(visited[x][y])
         continue;
      visited[x][y] = true;

      for(int i=0;i<4;i++)
      {
         int nx = x+dx[i];
         int ny = y+dy[i];
         if(nx>=0 && ny>=0 && nx<n && ny<m)
         {
            if(db[nx][ny]==1)
               air[nx][ny]++;
            else if(!visited[nx][ny])
               q.push({nx, ny});
         }
      }
   }
}


bool is_melted()
{
   bool flag = false;
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
         if(air[i][j]>1)
         {
            flag = true;
            db[i][j] = 0;
         }
      }
   }
return flag;

}



int main()
{
   cin>>n>>m;
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
         cin>>db[i][j];
      }
   }

   int ans = 0;

   while(true)
   {
      memset(visited, false, sizeof(visited));
      memset(air, 0, sizeof(air));
      
      spread();
      bool melt = is_melted();
      if(melt)
         ans++;
      else
         break;

   }

   cout<<ans<<endl;
    
}





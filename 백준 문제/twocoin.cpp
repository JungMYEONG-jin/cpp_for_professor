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
int ans;

char db[21][21];

int dx[4] = {1,-1,0,0};
int dy[4] = {0, 0, 1, -1};

bool is_valid(int x, int y)
{
   if(x>=0 && x<n && y>=0 && y<m)
      return true;
   return false;
}

void spread(int x, int y, int x2, int y2, int cnt, int dir)
{
   if(ans<cnt)
   {
      return;
   }
   if(cnt>10)
   {
      ans = min(ans, cnt);
      return;
   }

   int nx = x+dx[dir];
   int ny = y+dy[dir];
   int nx2 = x2+dx[dir];
   int ny2 = y2+dy[dir];

   if(!is_valid(nx, ny) && !is_valid(nx2, ny2))
      return;
   else if(is_valid(nx, ny) && !is_valid(nx2, ny2))
   {
      ans = min(ans, cnt);
      return;
   }else if(!is_valid(nx, ny) && is_valid(nx2, ny2))
   {
      ans = min(ans, cnt);
      return;
   }

   if(db[nx][ny]=='#')
   {
      nx = x;
      ny = y;
   }

   if(db[nx2][ny2]=='#')
   {
      nx2 = x2;
      ny2 = y2;
   }

   for(int i=0;i<4;i++)
   {
      spread(nx, ny, nx2, ny2, cnt+1, i);
   }


}


int main()
{
   cin>>n>>m;
   vector<pair<int, int>> res;
   for(int i=0;i<n;i++)
   {
      string str;
      cin>>str;
      for(int j=0;j<m;j++)
      {
         db[i][j] = str[j];
         if(db[i][j]=='o')
         {
            res.push_back({i,j});
         }
      }
      
        
   }
   ans = INF;
   for(int i=0;i<4;i++)
   {
      auto it = res[0];
      auto it2 = res[1];
      spread(it.first, it.second, it2.first, it2.second, 1, i);
   }
   
   if(ans>10)
      cout<<-1<<endl;
   else
      cout<<ans<<endl;
    
}





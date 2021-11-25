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
int dx[] = {0,0,1,-1,0,0};
int dy[] = {0,0,0, 0, 1, -1};




int main()
{  
   while(true)
   {

      char db[30][30][30];
      bool visited[30][30][30];

      cin>>a>>b>>c;

      if(a==0 && b==0 && c==0)
        break;

         int sx, sy, sz;
         int ex, ey, ez;

      for(int i=0;i<a;i++)
      {

         for(int j=0;j<b;j++)
         {
            string str;
            cin>>str;
            for(int k=0;k<c;k++)
            {
               db[i][j][k] = str[k];
               if(str[k]=='S')
               {
                 sz = i;
                 sx = j;
                 sy = k;
               }else if(str[k]=='E')
               {
                 ez = i;
                 ex = j;
                 ey = k;
               }
            }
         }
      }

      memset(visited, false, sizeof(visited));

      int escape = 0;

      visited[sz][sx][sy] = true;
      queue<tuple<int, int, int, int>> q;
      q.push({sz, sx, sy, 0});
      while(!q.empty())
      {
         auto it = q.front();
         q.pop();
         int z, x, y, cnt;
         tie(z, x, y, cnt) = it;
         
         if(z==ez && x==ex && y==ey)
         {
            escape = cnt;
            break;
         }

         for(int i=0;i<6;i++)
         {
            int nz = z+dz[i];
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nz>=0 && nx>=0 && ny>=0 && nz<a && nx<b && ny<c)
            {
               if(!visited[nz][nx][ny] && db[nz][nx][ny]!='#')
               {
                  visited[nz][nx][ny] = true;
                  q.push({nz, nx, ny, cnt+1});
               }
            }



         }



      }


      if(visited[ez][ex][ey])
         cout<<"Escaped in "<<escape<<" minute(s).\n";
      else
         cout<<"Trapped!\n";



 }




    
}





#include <vector>
#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>
#include <tuple>
#include <set>

using namespace std;


bool visited[100][100][2];
int db[100][100];


int n, m;

int dx[] = {1,-1, 0, 0};
int dy[] = {0, 0, 1, -1};


bool is_valid(int x, int y)
{
   if(x>=0 && y>=0 && x<n && y<m)
      return true;
   return false;
}


int main()
{
   int t;
	cin>>n>>m>>t;

   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
         cin>>db[i][j];
   }  

   memset(visited, false, sizeof(visited));
  
   visited[0][0][0] = true; // x y gram
   queue<tuple<int, int, int, int>> q;
   q.push({0,0,0,0}); // x y gram cnt
   int step = 0;

   while(!q.empty())
   {
      auto it = q.front();
      int x, y, gram, cnt;
      tie(x, y, gram, cnt) = it;
      q.pop();
      //cout<<x<<" "<<y<<" "<<gram<<" "<<cnt<<endl;
      if(x==n-1 && y==m-1)
      {
         step = cnt;
         break;
      }

      if(db[x][y]==2)
         gram = 1;

      for(int i=0;i<4;i++)
      {
         int nx = x+dx[i];
         int ny = y+dy[i];

         if(is_valid(nx, ny))
         {
            if(gram==0 && !visited[nx][ny][gram] && db[nx][ny]==0)
            {
               q.push({nx, ny, gram, cnt+1});
               visited[nx][ny][gram] = true;
            }
            if(gram==0 && !visited[nx][ny][gram] && db[nx][ny]==2) // gram
            {
               q.push({nx, ny, gram, cnt+1});
               visited[nx][ny][gram] = true;
               
            }
            if(gram==1 && !visited[nx][ny][gram])
            {
               q.push({nx, ny, gram, cnt+1});
               visited[nx][ny][gram] = true;
            }
         }
      }

   }

   if(step<=t && step>0)
      cout<<step;
   else
      cout<<"Fail";




}

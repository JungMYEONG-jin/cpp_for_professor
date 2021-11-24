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

int n, m;

int dx[4] = {1,-1,0,0};
int dy[4] = {0, 0, 1, -1};

int db[51][51];
int dist[51][51];

int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
     string str;
     cin>>str;
     for(int j=0;j<n;j++)
     {
        db[i][j] = str[j]-'0';
     }

   
  }


  for(int i=0;i<n;i++)
  {
     for(int j=0;j<n;j++)
     {
        dist[i][j]=INF;
     }

  }
  dist[0][0] = 0; // change 0
  queue<pair<int, int>> q;
  q.push({0, 0});



  

  while(!q.empty())
  {
     auto it = q.front();
     int x = it.first;
     int y = it.second;
     q.pop();
     for(int i=0;i<4;i++)
     {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0 && ny>=0 && nx<n && ny<n)
        {
          if(db[nx][ny]==1)
          {
             if(dist[nx][ny]>dist[x][y])
             {
                dist[nx][ny] = dist[x][y];
                q.push({nx, ny});
             }
          }else
          {
             if(dist[nx][ny]>dist[x][y]+1)
             {
                dist[nx][ny] = dist[x][y]+1;
                q.push({nx, ny});
             }
          }



        }
     }
  }

   cout<<dist[n-1][n-1];


    
}





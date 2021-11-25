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


int db[100][100];
bool visited[100][100];

int main()
{  
  int n;
  cin>>n;
  bool flag = true;
  int fx, fy;
  for(int i=0;i<n;i++)
  {
     for(int j=0;j<n;j++)
     {
        cin>>db[i][j];
        if(flag && db[i][j]==1)
         {
            fx = i;
            fy = j;
            flag = false;
         }
     }
  }

   vector<vector<pair<int, int>>> graph;
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
         if(!visited[i][j] && db[i][j]==1)
         {
            vector<pair<int, int>> temp;
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            while(!q.empty())
            {
               auto it = q.front();
               int x = it.first;
               int y = it.second;
               temp.push_back({x, y});

               q.pop();

               for(int k=0;k<4;k++)
               {
                  int nx = x+dx[k];
                  int ny = y+dy[k];

                  if(nx>=0 && ny>=0 && nx<n && ny<n)
                  {
                     if(!visited[nx][ny] && db[nx][ny]==1)
                     {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                     }
                  }
               }


            }
            graph.push_back(temp);
         }
      }
   }

   int result = 999999;

   for(int i=0, len = graph.size();i<len;i++)
   {
      
      for(int j=i+1;j<len;j++)
      {
         for(const auto it : graph[i])
         {
            for(const auto it2 : graph[j])
            {
               result = min(result, abs(it.first-it2.first)+abs(it.second-it2.second));
            }
         }      
      }
   }
   

cout<<result-1<<endl;

    
}





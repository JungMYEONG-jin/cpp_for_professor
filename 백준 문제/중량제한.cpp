#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <tuple>
#include <set>
#include <algorithm>



#define INF 999999999

using namespace std;

int n;
int start, dest;

bool visited[100001];
vector<pair<int, int>> graph[100001];

bool bfs(int val)
{
   visited[start] = true;
   queue<int> q;
   q.push(start);

   while(!q.empty())
   {
      int cur = q.front();
      q.pop();

      if(cur==dest)
      {
         return true;
      }

      for(auto it : graph[cur])
      {
         if(!visited[it.first] && val<=it.second)
         {
            q.push(it.first);
            visited[it.first] = true;
         }
      }
   }
   return false;

}




int main()
{
  int m;
  cin>>n>>m;
  int x, y, cost;
  for(int i=0;i<n;i++)
  {
     cin>>x>>y>>cost;
     graph[x].push_back({y, cost});
     graph[y].push_back({x, cost});
  }

  cin>>start>>dest;
  int low = 0;
  int high = 1000000000;
  while(low<=high)
  {
     int mid = (low+high)>>1;
     if(bfs(mid))
     {
        low = mid+1;
     }else
     {
        high = mid-1;
     }
     memset(visited, false, sizeof(visited));
   
  }

  cout<<high<<endl;

}






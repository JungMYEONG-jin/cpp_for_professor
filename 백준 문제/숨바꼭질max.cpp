#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <tuple>
#include <set>
#include <algorithm>



#define INF 999999999

using namespace std;

int n, m;

int dist[20001];
vector<int> graph[20001];
set<int> ans;

int main()
{
   cin>>n>>m;
   int x, y;

   for(int i=1;i<=n;i++)
      dist[i] = INF;


   for(int i=0;i<m;i++)
   {
      cin>>x>>y;
      graph[x].push_back(y);
      graph[y].push_back(x);
   }
   queue<pair<int ,int>> q;
   q.push({1, 0});
   dist[1] = 0;
   int mval = 0;
   while(!q.empty())
   {
      auto it = q.front();
      q.pop();
      int cur = it.first;
      int cost = it.second;

      for(int num : graph[cur])
      {
         int ncost = cost+1;
         if(dist[num]>ncost)
         {
            dist[num] = ncost;
            q.push({num, ncost});
            if(dist[num]>mval)
            {
               mval = dist[num];
               ans.clear();
               ans.insert(num);
            }else if(dist[num]==mval)
               ans.insert(num);
         }
      }

   }


   cout<<*ans.begin()<<" "<<mval<<" "<<ans.size()<<endl;

}






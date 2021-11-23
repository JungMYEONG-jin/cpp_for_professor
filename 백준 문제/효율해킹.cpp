#include <vector>
#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;


bool visited[10001];
vector<int> graph[10001];
int n,m;
int main()
{
	cin>>n>>m;
   for(int i=0;i<m;i++)
   {
      int x, y;
      cin>>x>>y;
      graph[y].push_back(x);
   }

   queue<int> q;
   vector<pair<int, int>> res;
   for(int i=1;i<=n;i++)
   {
      q.push(i);
      int hack = 0;
      memset(visited, false, sizeof(visited));
      visited[i] = true;
      while(!q.empty())
      {
         int cur = q.front();

         q.pop();
         for(auto num : graph[cur])
         {
            if(!visited[num])
            {
               visited[num] = true;
               q.push(num);
               hack++;
            }
         }


      }
      res.push_back({i, hack});
   }



   sort(res.begin(), res.end(), [](auto e, auto k){return e.second>k.second || e.second==k.second && e.first<k.first;});
   // 내림차순 정렬
   int mval = res[0].second;
   for(const auto& it : res)
   {
      if(it.second==mval)
         cout<<it.first<<" ";
      else
          break;
   }

   

}

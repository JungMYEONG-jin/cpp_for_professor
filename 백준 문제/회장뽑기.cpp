#include <vector>
#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>
#include <tuple>
#include <set>

#define INF 999999999

using namespace std;

int dist[51][51];


int main()
{
   int n;
   cin>>n;

   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=n;j++)
      {
         if(i==j)
            continue;
         else
            dist[i][j]=INF;

      }
   }

   while(true)
   {
      int a, b;
      cin>>a>>b;
      if(a==-1 && b==-1)
         break;
      dist[a][b] = 1;
      dist[b][a] = 1;
   }



   vector<int> db;
   int result = INF;

   for(int k=1;k<=n;k++)
   {
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=n;j++)
         {
            if(dist[i][j]>dist[i][k]+dist[k][j])
            {
               dist[i][j] = dist[i][k]+dist[k][j];
            }
         }
      }
   }
   
   for(int i=1;i<=n;i++)
   {
      int mval = 0;
      for(int j=1;j<=n;j++)
      {
         mval = max(mval, dist[i][j]);
      }

      if(mval<result)
      {
         db.clear();
         result = mval;
         db.push_back(i);
      }else if(mval==result)
      {
         db.push_back(i);
      }


   }

   sort(db.begin(), db.end());
   cout<<result<<" "<<db.size()<<endl;
   for(const auto i : db)
      cout<<i<<" ";


   

  

}

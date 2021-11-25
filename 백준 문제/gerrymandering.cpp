#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <tuple>
#include <set>


#define INF 999999999

using namespace std;


int n, m;
int dx[4] = { 1,-1, 0,0 };
int dy[4] = { 0,0,1,-1 };
bool con[11][11];
int db[11];
bool visited[11];
bool selected[11];
int ans = INF;

bool con_check(vector<int>& v, bool t)
{
   memset(visited, false, sizeof(visited));
   visited[v[0]] = true;
   queue<int> q;
   q.push(v[0]);
   int num = 1;
   
   while(!q.empty())
   {
      int cur = q.front();
      q.pop();
     
      for(int i=1;i<=n;i++)
      {
         if(con[cur][i] && selected[i]==t && !visited[i])
         {
            visited[i] = true;
            q.push(i);
            num++;
         }
      }
      
   }
   if(num==v.size()) // all connected
         return true;
   return false;
}

bool check()
{
   vector<int> a, b;
   for(int i=1;i<=n;i++)
   {
      if(selected[i])
         a.push_back(i);
      else
         b.push_back(i);
   }


   if(a.empty() || b.empty())
      return false;
   

   if(!con_check(a, true) || !con_check(b, false))
      return false;
   
   return true;

}


void calc()
{
   vector<int> a, b;
   int a_sum =0;
   int b_sum = 0;
   for(int i=1;i<=n;i++)
   {
      if(selected[i])
         a_sum+=db[i];
      else
         b_sum+=db[i];
   }

   int diff = abs(a_sum-b_sum);
   ans = min(ans, diff);
}

void dfs(int idx, int cnt)
{
   if(cnt>=1)
   {
      if(check())
      {
         calc();
      }
   }


   for(int i = idx;i<=n;i++)
   {
      if(selected[i])
         continue;
      selected[i] = true;
      dfs(i, cnt+1);
      selected[i] = false;
   }
}





int main()
{
    
   cin>>n;
   for(int i=1;i<=n;i++)
   {
      cin>>db[i];
      
   }
   

   for(int i=1;i<=n;i++)
   {
      int t, val;
      cin>>t;
      for(int j=0;j<t;j++)
      {
         cin>>val;
         con[i][val] = true;
         con[val][i] = true;
      }
   }
   dfs(1, 0);
   if(ans==INF)
      cout<<-1<<endl;
   else
      cout<<ans<<endl;




}






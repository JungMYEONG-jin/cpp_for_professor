#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <tuple>
#include <set>
#include <algorithm>



#define INF 999999999

using namespace std;

int n, m, limit;

bool visited[100000];
int db[100000];

int main()
{
   cin>>n>>limit>>m;

   queue<pair<int, int>> q;
   q.push({n, 0}); // start 0
   visited[n] = true;
   int ans = 0;
   bool flag = false;
   while(!q.empty())
   {
      auto it = q.front();
      q.pop();
      int cur = it.first;
      int cnt = it.second;
      //cout<<cur<<" "<<cnt<<endl;
      if(cur==m)
      {
         ans = cnt;
         flag = true;
         break;
      }

      if(cur+1<=99999 && !visited[cur+1])
      {
         q.push({cur+1, cnt+1});
         visited[cur+1] = true;
      }

      if(2*cur<=99999)
      {
         int val = cur*2;
         string str = to_string(val);
         if(str[0]>'0')
            str[0] = (str[0]-'1')+'0';
         val = stoi(str);
         if(!visited[val])
         {
            q.push({val, cnt+1});
            visited[val] = true;
         }
      }


   }
   if(ans<=limit && flag)
      cout<<ans<<endl;
   else
      cout<<"ANG"<<endl;

   return 0;

}






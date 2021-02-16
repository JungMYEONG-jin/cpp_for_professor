#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
   priority_queue<int,vector<int>, greater<int>> res;
   int n;
   cin>>n;
   int x;
   for(int i=0;i<n;i++)
   {
       cin>>x;
       res.push(x);
   }
   
   int sum=0;
   
   while(res.size()>1)
   {
       int a = res.top();
       res.pop();
       int b = res.top();
       res.pop();
       sum+=a+b;
       res.push(a+b);
      
   }
   
   cout<<sum<<endl;
   
   

    return 0;
}

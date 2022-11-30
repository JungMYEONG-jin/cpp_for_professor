#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using namespace std;

typedef long long ll;


int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   priority_queue<int> res;
   int t;
   cin>>t;
   int n, idx;
   int stage=0;
   int x;
   for(int i=0;i<t;i++)
   {
       cin>>n>>idx;
        vector<pair<int, int>> temp(n);
        stage=0;
    
    for(int i=0;i<n;i++)
    {
        cin>>x;
        temp[i] = {i, x};
        
    }
    
    auto it = temp[idx];
    //auto vec = temp;
    while(true)
    {
        auto k = temp[0];
        if(find_if(temp.begin(), temp.end(), [k](auto e){return e.second>k.second;})!=temp.end())
        {
            temp.push_back(temp.front());
            temp.erase(temp.begin());
            
        }else
        {
            if(temp[0]==it)
            {
                stage++;
                temp.erase(temp.begin());
                break;
            }
            temp.erase(temp.begin());
            stage++;
        }
        
    }
    
    
    
    cout<<stage<<'\n';
       
   }
   

 
    return 0;
}

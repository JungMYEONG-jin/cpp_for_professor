#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>

using namespace std;



int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
   
    int n;
    cin>>n;
    
    
    
    stack<pair<int, int>> res;
    // first score second deadline
    int x;
    int score;
    int deadline;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x==1)
        {
            cin>>score>>deadline;
            deadline--;
            if(deadline>0)
                res.push({score, deadline});
            else
                sum+=score;
        }else if(x==0 && !res.empty())
        {
            auto k = res.top();
            res.pop();
            k.second--;
            if(k.second==0)
            {
                sum+=k.first;
            }else
                res.push(k);
        }
    }
    
    
    
    
    cout<<sum<<'\n';

    
    return 0;
}

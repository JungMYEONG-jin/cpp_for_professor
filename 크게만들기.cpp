#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <cmath>


using namespace std;

typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    string number;
    cin>>number;
    
    stack<char> res;
    
    int len = n-k;
    for(auto i : number)
    {
        while(k && !res.empty() && res.top()<i)
        {
            res.pop();
            k--;
        }
        
        
        res.push(i);
    }
    
    
    
    number = "";
    while(!res.empty())
    {
        number+=res.top();
        res.pop();
    }
    
    reverse(number.begin(), number.end());
    
    cout<<number.substr(0, len)<<'\n';
    
    
    
    
    return 0;
    
    
    
    
    
    
    
}

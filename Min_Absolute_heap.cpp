#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main()
{
    ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    
    vector<int> res;
    
    
    int n;
    cin>>n;
    
    
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x!=0)
            res.push_back(x);
        else
        {
            if(res.size()>0)
            {
            auto it = min_element(res.begin(), res.end(), [](auto e, auto k){
                return abs(e)<abs(k) || abs(e)==abs(k) && e<k;
            });
            cout<<*it<<'\n';
            res.erase(it);
            }
            else
                cout<<0<<'\n';
        }
        
    }
    
    
    
    
    
}

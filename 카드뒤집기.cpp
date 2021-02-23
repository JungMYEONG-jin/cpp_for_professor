#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int count1=0;
    int count2=0;
    
    string str;
    cin>>str;
    auto it = str.find('1');
    auto it2 = str.find('0');
    if(it!=str.npos)
        count1++;
    if(it2!=str.npos)
        count2++;
    if(it<it2)
    {
    while(it!=str.npos || it2!=str.npos)
    {
        it = str.find('1', it2);
        if(it!=str.npos)
            count1++;
        //cout<<it<<endl;
        it2 = str.find('0', it);
        if(it2!=str.npos)
            count2++;
        //cout<<it2<<endl;
    }
    }else
    {
        
        while(it!=str.npos || it2!=str.npos)
    {
        
        it2 = str.find('0', it);
        if(it2!=str.npos)
            count2++;
        
        it = str.find('1', it2);
        if(it!=str.npos)
            count1++;
    }
        
        
        
    }
    
    
    cout<<min(count1, count2)<<'\n';
    
    return 0;
    
    
}

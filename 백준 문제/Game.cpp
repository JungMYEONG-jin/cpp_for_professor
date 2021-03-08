#include <iostream>

using namespace std;

int main()
{
    long long x, y;
    cin>>x>>y;
    
    int z = (y*100)/x; // prob
    if(z>=99)
    {
        cout<<-1;
        return 0;
    }
    long long left=1;
    long long right = 1000000000;
    long long num = 1000000000;
    while(left<=right)
    {
        
        long long mid = (left+right)/2;
        int prob = ((y+mid)*100)/(x+mid);
        
        if(prob<=z)
        {
            left = mid+1;
        }else
        {
            right = mid-1;
            num = min(num, mid);
            
        }
        
        
        
    }
    
    
    
    
    cout<<num<<'\n';
    
    
    
    return 0;
    
    
    
    
    
    
}

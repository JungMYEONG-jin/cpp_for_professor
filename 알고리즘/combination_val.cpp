#include <cmath>


using namespace std;






class ColorChoice
{
public:
    static long long checkChoose(long long m, int n)
    {
    
    long x = 1;
    
    for(int i=1;i<n;i++)
    {
     x= round(x*(n-i+1)/i);
     if(m==x)
      return i;
    
    
    
    
    }
    return -1;
    
    }
    
    
 };

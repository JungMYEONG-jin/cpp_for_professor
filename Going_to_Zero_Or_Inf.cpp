#include <cmath>

using namespace std;

class Suite
{
public:
  static double going(int n)
  {
    
    
    double r=1, a=1;
    for(int i=0;i<n-1;i++)
    {
      a = a/(n-i);
      r=r+a;
    }
    return floor(r*1000000)/1000000;
    
  }
};

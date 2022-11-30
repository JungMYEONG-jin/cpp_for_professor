#include <vector>
#include <cmath>
using namespace std;

class RemovedNumbers
{
public:
  static vector<vector<long long>> removNb(long long n)
  {
    vector<vector<long long>> res;
    vector<long long> test;
    
    long long val = (n+1)*n/2;
    long long a=0;
    long double b=0;
    for(int i=1;i<n;i++)
    {
      b = (val-i)/(i+1.0);
      if(b==floor(b) && b<=n)
        res.push_back(vector<long long> {i,static_cast<long long>(b)});
      
    }
 
    return res;
  }
};

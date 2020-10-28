#include <vector>
#include <utility>
#include <cmath>

using namespace std;

class Dioph
{
  public:
  static std::vector<std::pair <long, long>> solEquaStr(long long n)
    {
    
    vector<pair<long, long>> res;
    
    for(long long i =1;i<sqrt(n)+1;i++)
    {
      
      if(n%i==0)
      {
        long long j = n/i;
        if((i+j)%2==0 && (j-i)%4==0)
          res.push_back(make_pair((i+j)/2, (j-i)/4));
        
      }
      
      
    }
    
    return res;
    
  }
};

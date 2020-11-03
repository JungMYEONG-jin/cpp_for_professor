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














/* BEST CODE
#include <vector>

using namespace std;

class RemovedNumbers
{
public:
  static vector<vector<long long>> removNb(long long n);
};

vector<vector<long long> > RemovedNumbers::removNb(long long n)
{
    vector<vector<long long> >  result;
    
    long long  total = (n + 1) * n / 2;
    
    for( long long a = n/2; a <= n; ++a )
    {
         long long  b = (total - a) / (a + 1);
         
         if( total == (a * b + a + b) )
         {
             vector<long long>  one_pair;
            
             one_pair.push_back( a );
             one_pair.push_back( b );
            
             result.push_back( one_pair );
         }
        
    }
    
    return result;
}

*/

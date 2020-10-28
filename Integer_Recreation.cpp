#include <cmath>

using namespace std;

class SumSquaredDivisors
{
public:
    static std::string listSquared(long long m, long long n);
};

string SumSquaredDivisors::listSquared(long long m, long long n)
{
  string ret;
  for (int i = m; i <= n; i++) {
    int sum = 0;
    for (int j = 1; j <= i; j++)
      if (i % j == 0) sum += j * j;
    double sqrt_sum = sqrt(sum);
    if (floor(sqrt_sum) == sqrt_sum)
      ret += "{" + to_string(i) + ", " + to_string(sum) + "}, ";
  };
  return "{" + ret.substr(0, ret.size() - 2) + "}";
}

/* MYCODE




#include <utility>
#include <vector>
#include <cmath>
using namespace std;
vector<long long> div_sum(long long n)
{
  vector<long long> sum;
  
  sum.push_back(1);
  if(n==1)
    return sum;
  
  
  sum.push_back(n);
  for(int i=2;i<=sqrt(n);i++)
  {
    if(n%i==0)
    {
      
      
      sum.push_back(i);
      sum.push_back(n/i);
    }
  }

  sort(sum.begin(), sum.end());
  sum.erase(unique(sum.begin(), sum.end()),sum.end());
  
  return sum;
}




class SumSquaredDivisors
{
public:
    static std::vector<std::pair<long long, long long>> listSquared(long long m, long long n)
    {
      
      vector<pair<long long, long long>> res;
      
      for(long long i=m;i<=n;i++)
      {
        long long t=0;
        vector<long long> k = div_sum(i);
        for(auto i : k)
          t+=i*i;
        
        
        if(floor(sqrt(t))*floor(sqrt(t))==t)
          res.push_back(make_pair(i, t));
        
        
      }
      
      return res;
    }
};





*/

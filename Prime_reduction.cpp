#include <string>
#include <cmath>

using namespace std;

bool isPrime(long long n)
{
  if(n==1 || n==0)
    return false;
  
  for(int i=2;i<=sqrt(n);i++)
    if(n%i==0)
      return false;
  return true;
}



std::vector<unsigned> not_primes(unsigned a, unsigned b)
{
    vector<unsigned> res;
    if(b<=21)
      return {};
    
    for(unsigned i=a;i<b;i++)
    {
      if(!isPrime(i))
      {
        
        string k = to_string(i);
        int len = 0;
        for(auto j : k)
        {
          if(isPrime(j-'0'))
            len++;
        }
        if(len==k.size())
          res.push_back(i);
        
      }
    }
  return res;
}

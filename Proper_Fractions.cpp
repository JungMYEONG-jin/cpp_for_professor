#include <cmath>
#include <vector>
using namespace std;




long long get_factor(long long n)
{
  
  long long i =2;
  long long  res = 1.0*n;
  while(i*i<=n)
  {
    if(n%i==0)
      {
    while(n%i==0)
      {
      n/=i;
       }
      res*=(1.0-(1.0/i));
      }
  
    i++;
    
  }
  
  if(n>1)
    res*=(1.0-(1.0/n));
  
  
  return res;

}


long long properFractions(long long n)
{
  
  
  
    if(n<=1)
      return 0;
   
   return get_factor(n);
}

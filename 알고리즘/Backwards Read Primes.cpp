#include <cmath>

using namespace std;

bool isPrime(long long n)
  {
  for(int i=2; i<=sqrt(n);i++)
    {
    if(n%i==0)
      return false;
  }
  return true;
}

class BackWardsPrime
{
public:
  static std::string backwardsPrime(long long start, long long end)
    {
    string res="";
  
    for(long long i = start;i<=end;i++)
      {
      string j = to_string(i);
      reverse(j.begin(), j.end());
      long long temp = stoll(j);
     if(i!=temp && isPrime(i) && isPrime(temp))
       res+=to_string(i)+" ";
      
    }
    if(res.empty())
      return {};
    res.pop_back();
    return res;
    
  }
};




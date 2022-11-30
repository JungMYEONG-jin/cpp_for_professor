#include <vector>
#include <set>
using namespace std;


long long gcd(long a, long b)
{
  while(b!=0)
  {
    long c = a%b;
    a = b;
    b= c;
  }
  return a;
}




vector<long long> get_seq(long long n)
{
  vector<long long> res;
  res.push_back(7);
  
  long long i = 2;
  long long idx = 0;
  while(i<=n)
  {
    res.push_back(res[idx]+gcd(i, res[idx]));
    idx++;
    i++;
  }
  
  return res;
  
}

vector<long long> gn(long long n)
{
  vector<long long> g(n);
  g[0] = 1;
  auto res = get_seq(n);
  
  for(long long i=0;i<res.size()-1;i++)
      {
        g[i+1] = (res[i+1]-res[i]);
      }
  return g;
}

vector<long long> pn(long long n)
{
  auto res = gn(20000*n);
   vector<long long> p;
  
  for(auto i : res)
  {
    if(i!=1 && find(p.begin(), p.end(), i)==p.end())
      p.push_back(i);
    
    if(p.size()==n)
      break;
  }
  
  return p;
  
  
}


class WeirdPrimeGen
{
public:
    static long long countOnes(long long n)
    {
      auto res = gn(n);
      
      return count(res.begin(), res.end(), 1);
    }
    static long long maxPn(long long n)
    {
      auto res = pn(n);
      
      return *max_element(res.begin(), res.end());
    }
    static int anOverAverage(long long n)
    {
      auto a  = get_seq(10000*n);
      auto g  = gn(10000*n);
      double avg = 0.0;
      int count=0;
    
      for(int i=0;i<a.size();i++)
      {
        if(g[i]!=1)
        {
          avg+=a[i]/(i+1);
          count++;
        }
        if(count==n)
          break;
      }
      
      return avg/count;
    }
};

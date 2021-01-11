#include <cmath>
using namespace std;


class SqProd2Sum
{
public:
    static std::vector<std::pair <long, long>> prod2Sum(long long a, long long b, long long c, long long d);
};


vector<pair<long, long>> SqProd2Sum::prod2Sum(long long a, long long b, long long c, long long d)
{
 
  vector<pair<long, long>> res;
   if(a==0 && b==0 && c==0 && d==0)
    {
     res.push_back({0,0});
     return res;
   }
  long long left= a*a + b*b;
  long long right = c*c+d*d;
  
  long long prod = left*right;
  
  
  long long case1=a*c;
  long long case1_ = b*d;
  
  long long case2= a*d;
  long long case2_ = b*c;
  if(a<0)
    a*=-1;
  if(b<0)
    b*=-1;
  if(c<0)
    c*=-1;
  if(d<0)
    d*=-1;

  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl; 
  long i =0;
  while(i*i<prod)
  {
    
    double k = prod;
    k-=i*i;
    
    if(sqrt(k)==floor(sqrt(k)))
    {
      
      if((i==abs(a*d-b*c) &&  sqrt(k)==a*c+b*d)  || (i==abs(a*c-b*d) && sqrt(k)==a*d+b*c))
        if(find_if(res.begin(), res.end(), [&k](auto e){return e.first==sqrt(k) || e.second==sqrt(k);})==res.end())
        {
          if(i<=sqrt(k))
            res.push_back({i, sqrt(k)});
          else
            res.push_back({sqrt(k), i});
        }
    }
    
    
    
    i++;
  }
  
  
  
  return res;
  
}

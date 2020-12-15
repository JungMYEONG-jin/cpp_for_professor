#include<cstdint>
#include <cmath>
#include <map>
using namespace std;



int64_t lcmCardinality(int64_t n){
  // your code here
  auto k = n;
  map<int, int> res;
  int i=2;
  while(i*i<=n)
  {
    while(n%i==0)
    {
      n/=i;
      res[i]++;
    }
    i++;
  }
  if(n>1)
    res[n]++;
  int count=1;
 
  for(auto it : res)
  {
    count*=(2*it.second+1);
  }
  

return count/2+1;
  
}

#include <numeric>
#include <algorithm>
#include <array>
using namespace std;

int gcds(int a, int b)
{
  int c;
  while(b!=0)
  {
    c = a%b;
    a = b;
    b=c;
  }
  return a;
}




bool hasSubpattern(const std::string& str){
  //your code here
  array<int, numeric_limits<char>::max()> res{};
  
  for(auto i : str)
  {
    res[i]++;
    
  }
 return std::accumulate(res.begin(), res.end(), 0,[](auto e, auto k){return gcds(e, k);} )!=1;
}

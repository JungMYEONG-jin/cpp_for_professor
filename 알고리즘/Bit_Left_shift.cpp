#include <bitset>
#include <string>
#include <cmath>
using namespace std;


int nextHigher(int n)
{
  
    if(n==0)
      return 1;
    if (n==-1)
      return 0;
  
  
    
    bitset<8> r(n);
    string k = r.to_string();
  
    if(n<0)
    {
      r.flip();
      
      k = r.to_string();
      reverse(k.begin(), k.end());
      
      auto p = k.find_last_of('1');
      return -pow(2,p);
      
    }
  
  
    if (count(k.begin(), k.end(), '1') == 1)
    {
      r = r << 1;
      return r.to_ulong();
    }
    else
    {
      reverse(k.begin(), k.end());
      auto p = k.find_last_of('1');
      return pow(2,p+1);
    } 














/* BEST CODE

int nextHigher(int n) {
  if (n < -1) {
    n &= n >> 1; n &= n >> 2; n &= n >> 4; n &= n >> 8; n &= n >> 16;
    return n >> 1;
  } else {
    n |= n >> 1; n |= n >> 2; n |= n >> 4; n |= n >> 8; n |= n >> 16;
    return n + 1;
  }
}

*/

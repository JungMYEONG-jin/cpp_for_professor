#include <cmath>

using namespace std;

bool is_square(int n)
{
  // TODO
  if(n==-1)
    return false;
  if(n==0)
    return true;
  
  double k = sqrt(n);
  
  return k==floor(k);
  
}

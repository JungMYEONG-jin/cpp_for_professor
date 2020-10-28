#include <cmath>

using namespace std;

// Returns number of complete beeramid levels
int beeramid(int bonus, double price)
{
  
  int n=1;
  while(bonus>0)
  {
    bonus -=price*pow(n,2);
    if(bonus<0)
      break;
    n++;
    
    
   
  }
  
  
  return n-1;
}

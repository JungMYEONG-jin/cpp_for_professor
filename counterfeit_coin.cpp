include <cmath>
using namespace std;
unsigned int howManyMeasurements(unsigned int n){
  //your code here
  
  int i=0;
  if(n==0)
    return 0;
  
  while(n>pow(3,i))
  {
    
    i++;
    
    
  }
  
  
  return i;
}

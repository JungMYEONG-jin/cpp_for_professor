#include <iostream>

using namespace std;

long long int sequence_sum(long long int begin_number, long long int end_number, long long step){
    //your code here

  long long int sum=0;
  
  if(begin_number<0 && end_number<0)
  {
    
    if(begin_number<end_number && step<0)
      return 0;
    if(begin_number>end_number && step>0)
      return 0;
    
     int n = (-end_number+begin_number)/-step;
  
    return ((n+1)*(begin_number+begin_number+n*step)/2);
  }
  
 
    if(begin_number>end_number && step>0 || (begin_number<end_number && step<0))
      return 0;
  
   int n = (end_number-begin_number)/step;
  
  return (n+1)*(begin_number+begin_number+n*step)/2;
  
 
  
}

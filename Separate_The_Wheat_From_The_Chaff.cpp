#include <vector>
#include <algorithm>
using namespace std ; 

vector <long long int> wheatFromChaff (vector <long long int> values)
{
  // Your Code is Here .. Enjoy !! 
  
  if(values.empty())
    return values;
  
  long long int head = 0;
  long long int tail = values.size()-1 ;
  for ( head = 0; head < tail; head++ , tail--) {
    while (values[head] < 0) head++;
    while (values[tail] > 0) tail--;
    if (head < tail && head<values.size() && tail>0)
      {
      auto temp = values[tail];
      values[tail]=values[head];
      values[head] = temp;
       
       }
  }
  return values;
}

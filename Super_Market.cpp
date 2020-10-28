#include <algorithm>
#include <map>
using namespace std;

long queueTime(std::vector<int> customers,int n){

   if(n==1)
    {
     
     int sum=0;
     for(auto i : customers)
       sum+=i;
     return sum;
     
     
   }
 
  vector<int> timer(n);

  for(auto c : customers)
  {
    timer[0]+=c;
    sort(timer.begin(), timer.end());
  }
  
 
 
  
  
  return *max_element(timer.begin(), timer.end());
}

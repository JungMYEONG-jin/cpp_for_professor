#include <cmath>


using namespace std;


int comparePowers(std::pair<long, long> n1, std::pair<long, long> n2){
  //your code here
  
 //use log transform
  
  auto val1 = log10(n1.first)*n1.second;
  auto val2 = log10(n2.first)*n2.second;
  
  return (val1-val2)>0?-1:(val1==val2?0:1);  
  
  
  
  
}

#include <numeric>
#include <algorithm>
using namespace std;

int targetGame(const std::vector<int>& values) {
  // your code goes here
  
  int a =0, b=0;
  for(auto i : values)
  {
    int k =a;
    a=b;
    b=max(k+i,b);
  }
  return max(a,b);
}

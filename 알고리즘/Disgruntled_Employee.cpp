#include <cmath>

using namespace std;

vector<int> off(int n) {
  // your code
  vector<int> res;
  for(int i=1;i<=sqrt(n);i++)
    res.push_back(i*i);
  
  return res;
  
  
}

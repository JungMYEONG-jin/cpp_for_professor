#include <vector>
#include <cstdlib>
using namespace std;
std::vector<std::vector<int>> pyramid(std::size_t n) {
  // your code here
  if(n==0)
    return {};
  vector<vector<int>> res;
  for(int i=1;i<=n;i++)
    res.push_back(vector<int>(i,1));
  
  return res;
  
  
}

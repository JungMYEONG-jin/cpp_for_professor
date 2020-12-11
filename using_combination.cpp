#include <vector>
#include <algorithm>

using namespace std;


int solve(const std::vector<std::vector<int>> &data)
{
  vector<vector<int>> res = data;
    int count=1;
    for(auto& it : res)
    {
      
      sort(it.begin(), it.end());
      it.erase(unique(it.begin(), it.end()), it.end());
      count*=it.size();
      
    }
  
  
  
    return count;
}

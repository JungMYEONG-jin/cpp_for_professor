#include <algorithm>

using namespace std;

int nthSmallest(std::vector<std::vector<int>> arr, int n)
{
  
    vector<int> res;
  
    for(auto it : arr)
      {
      for(auto i : it)
        res.push_back(i);
    }
  
    sort(res.begin(), res.end());
  
  
  
    return res[n-1];
}

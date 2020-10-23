#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

std::vector<std::pair<int, int>> twos_difference(const std::vector<int> &vec) {
  
  if(vec.size()<=1)
    return {};
  
  vector<pair<int, int>> res;
  for(int i=0;i<vec.size()-1;i++)
  {
   
    for(int j=i+1;j<vec.size();j++)
      {
      if(vec[i]-vec[j]==2)
        res.push_back(make_pair(vec[j], vec[i]));
      else if(vec[i]-vec[j]==-2)
        res.push_back(make_pair(vec[i],vec[j]));
    }
    
  }
  sort(res.begin(), res.end(), [](auto &e, auto& k){return e.first<k.first;});
  return res;
}

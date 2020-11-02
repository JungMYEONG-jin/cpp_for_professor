#include <vector>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;
int sum_intervals(std::vector<std::pair<int, int>> intervals) {
  
  set<int> res;
  sort(intervals.begin(), intervals.end(), [](auto e, auto k){
    return e.first<k.first || (e.first==k.first && e.second<k.second);
  });
  
  int cnt=intervals.size();
  for(auto i = intervals[0].first;i<intervals[0].second;i++)
    res.insert(i);
  
  
  for(auto i=1;i<intervals.size();i++)
  {
  
    for(int j=intervals[i].first;j<intervals[i].second;j++)
      res.insert(j);
  }

  int sum = res.size();
  
  
  return  sum;
}

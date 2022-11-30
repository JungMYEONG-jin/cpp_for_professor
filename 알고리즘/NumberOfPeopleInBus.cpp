#include <utility>
#include <vector>

unsigned int number(const std::vector<std::pair<int, int>>& busStops){
  //your code here
  int bus=0;
  
  for(auto i : busStops)
    {
    bus+=i.first-i.second;
  }
  
  return bus;
  
}

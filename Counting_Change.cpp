#include <vector>
using namespace std;
unsigned long long countChange(const unsigned int money, const std::vector<unsigned int>& coins) {
  // your code here
  vector<unsigned long long> res(money+1);
  res[0]=1;
  for(auto coin : coins)
  {
    for(unsigned long long i=coin;i<=money;i++)
      res[i]+=res[i-coin];
  }
  return res[money];
}

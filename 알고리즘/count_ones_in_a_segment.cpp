
#include <bitset>
#include <map>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

long long find_pattern(long long num, long long f)
{
  long long bit = 1<<f;
  long long chain = num>>(f+1);
  return bit*chain;
}

long long rest(long long num, long long f)
{
  long long bit = 1<<f;
  long long rest_num = num%(bit<<1);
  return std::max((long long)0, rest_num-bit+1);
}


long long calc(long long num, long long f)
{
  return find_pattern(num, f)+rest(num, f);
}

long long add_all(long long num)
{
  long long bit =0;
  long long total=0;
  while((num>>bit)>0)
  {
    total+=calc(num, bit);
    bit++;
  }
  return total;
}

long long countOnes ( long long left, long long right )
{
  return add_all(right)-add_all(left-1);









/* BEST CODE

long long countOnesFromZeroTo(int n) {
  long long res = 0;
  for (int i = std::numeric_limits<int>::digits - 1; i >= 0; i--) {
    int b = 1 << i;
    if (n & b)
      res += static_cast<long long>(i) * (b >> 1) + (n & b - 1) + 1;
  }
  return res;
}

long long countOnes(int left, int right) {
  return countOnesFromZeroTo(right) - countOnesFromZeroTo(left - 1);



*/

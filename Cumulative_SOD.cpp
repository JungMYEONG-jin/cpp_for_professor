// SOD(24) =35

#include <cstdint>

using namespace std;

uint64_t CSOD(const uint64_t n)
{

uint64_t sum = 0;
for(long i=2;i*i<=n;i++_
{
long long j = n/i;
sum+=(i+j)*(j+1-i)/2;
sum+=i*(j-i);



}

return sum;


}

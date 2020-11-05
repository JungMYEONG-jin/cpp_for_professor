#include <map>
#include <cmath>
using namespace std;

static long findMissing(std::vector<long> list){
 
    long n = list.size();
    long d = (list[n - 1] - list[0]) / n;
    long low = 0;
    long high = n - 1;

    while (low < high)
    {
        // Find the middle index
        int mid = low + (high - low) / 2;

        // if mid and the immediate next element to mid are not in AP, then missing element is arr[mid] + d.
        if (list[mid + 1] - list[mid] != d)
            return list[mid] + d;

        // if mid and the immediate previous element to mid are not in AP, then missing element is arr[mid-1] + d.
        if (mid > 0 && list[mid] - list[mid - 1] != d)
            return list[mid - 1] + d;

        // if elements of the left half are in AP, then missing element is in right half.
        if (list[mid] == list[0] + mid * d)
            low = mid + 1;

        // else missing element is in the left half.
        else
            high = mid - 1;
    }

  
  }












/* BEST CODE

static long findMissing(std::vector<long> list)
{
  long long expectedSum = (list.front() + list.back()) * (list.size() + 1);
  long long actualSum = std::accumulate(list.begin(), list.end(), 0ll);
  
  return (expectedSum - 2 * actualSum) / 2;
} 





*/

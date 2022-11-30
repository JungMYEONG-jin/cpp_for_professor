#include <vector>
#include <algorithm>
using namespace std;

std::vector<int> evenNumbers(std::vector<int> arr, int n) {
  //your code here
  vector<int> res;
  for(int i=arr.size()-1;i>=0;i--)
    {
    if(n>0 && arr[i]%2==0)
      {
      res.push_back(arr[i]);
      n--;
      }
    if(n<=0)
      break;
  }
  
  reverse(res.begin(), res.end());
  return res;
  
  
}

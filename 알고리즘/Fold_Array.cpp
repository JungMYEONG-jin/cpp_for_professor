#include <vector>
using namespace std;

vector<int> fold(vector<int> arr)
{
  
  if(arr.size()%2==1)
  {
    int mid  = arr.size()/2;
    
    for(int i=0;i<mid;i++)
    {
      arr[i] = arr[arr.size()-i-1]+arr[i];
      
    }
    for(int i=0;i<mid;i++)
    {
      arr.pop_back();
      
    }
    
    
  }else
  {
    int mid = arr.size()/2-1;
    for(int i=0;i<=mid;i++)
    {
      arr[i] = arr[arr.size()-1-i]+arr[i];
      
    }
    for(int i=0;i<=mid;i++)
    {
      arr.pop_back();
      
    }
    
  }
  
  return arr;
}



class Kata
{
public:
    std::vector<int> foldArray(std::vector<int> array, int runs)
    {
      vector<int> arr = array;
        for(int i=0;i<runs;i++)
        {
          arr = fold(arr);
        }
      return arr;
    }
};



/* BEST CODE
#include <algorithm>
#include <functional>
#include <vector>

struct Kata
{
    std::vector<int> foldArray(std::vector<int> a, int runs)
    {
      for (; runs > 0; --runs) 
      {
        const auto half = a.size() / 2;
        std::transform(std::cbegin(a), std::cbegin(a) + half, std::crbegin(a), std::begin(a), std::plus<int>());
        a.resize((a.size() + 1) / 2);
      }
      return a;
    }
};

*/

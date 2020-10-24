#include <algorithm>

using namespace std;

template<class TYPE>
int getLengthOfMissingArray(std::vector<std::vector<TYPE>> arrayOfArrays)
{
  
    if(arrayOfArrays.empty())
      return 0;
    for(auto i : arrayOfArrays)
      if(i.empty())
        return 0;
  
  
    int len=0;
    sort(arrayOfArrays.begin(), arrayOfArrays.end(), [](auto e, auto k){return e.size()<k.size();});
  
    for(int i=1;i<arrayOfArrays.size();i++)
    {
      if(arrayOfArrays[i].size()-arrayOfArrays[i-1].size()==1)
        continue;
      else
      {
        len = arrayOfArrays[i].size()-1;
        break;
      }
    }
  
    
  
  
  
  
  
    return len;
}

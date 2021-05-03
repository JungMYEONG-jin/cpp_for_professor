#include <vector>

using namespace std;



vector<int> eliminate(vector<int>& input)
{
  
  int len  = input.size();
  vector<int> temp;
  if(len%2==1)
    {
    
   
    
    for(int i=0;i<len-1;i+=2)
      {
      temp.push_back(input[i]>input[i+1]?input[i]:input[i+1]);
    }
    temp.insert(temp.begin(), input[len-1]); 
    
  }else
    {
    
   
      for(int i=0;i<len;i+=2)
        {
        temp.push_back(input[i]>input[i+1]?input[i]:input[i+1]);
      }

    }
    
    
    return temp;
    
    
  }
  





std::vector<std::vector<int>> tourney(const std::vector<int>& input) {
  // your code here
  
  vector<vector<int>> res;
  
  res.push_back(input);
  
  int idx=0;
  while(res[idx].size()>1)
    {
    
    res.push_back(eliminate(res[idx]));
    
    idx++;
  }
    
  
  
  return res;
  
}


// BEST CODE

#include <vector>

std::vector<std::vector<int>> tourney(const std::vector<int>& input) {
  std::vector<std::vector<int>> r;
  r.push_back(input);
  while (r.back().size() > 1) {
    std::vector<int> v;
    if (r.back().size()%2) v.push_back(r.back().back());
    for (auto i = r.back().begin(); i < r.back().end()-1; i += 2)
      v.push_back(std::max(*i,*(i+1)));
    r.push_back(v);
  }
  return r;
}
















//

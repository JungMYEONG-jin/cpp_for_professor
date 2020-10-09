#include <string>
#include <vector>

using namespace std;

std::vector<std::string> solution(const std::string &s)
{
  vector<string> res;
  string k=s;
  if(s.size()==1)
    {
    res.push_back(k+"_");
    return res;
  }
  
  
  
  for(int i=1;i<s.size();i++)
    {
    
    string temp = k.substr(0,2);
    if(temp.empty())
      break;
    if(temp.size()==1)
      {
      res.push_back(temp+"_");
      break;
    }
    k = s.substr(2*i);
    if(temp.size()==2)
      res.push_back(temp);
    
  }
  
    return res;
}

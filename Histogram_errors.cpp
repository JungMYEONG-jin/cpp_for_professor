#include <map>
#include <iomanip>

using namespace std;


std::string hist(const std::string &s)
{
    // your code
    string error = "uwxz";
    map<char, int> res;
    for(auto i : s)
    {
      if(error.find(i)!=error.npos)
        res[i]++;
      
    }
    
    string k;
    string re;
    for(auto it : res)
    {
      string len = to_string(it.second);
      k=string(1,it.first)+"  "+len+string(6-len.size(),' ')+string(it.second,'*')+"\\r";
      re+=k;
    }
  if(re.empty())
    return "";
  
  re.pop_back();
  re.pop_back();
  return re;

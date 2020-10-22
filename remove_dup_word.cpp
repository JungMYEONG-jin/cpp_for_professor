#include <string>
#include <set>
#include <sstream>
#include <map>
using namespace std;

std::string removeDuplicateWords(const std::string& str)
{
    
  string res="";
  map<string, bool> ms;
  stringstream sstr(str);
  string temp="";
  while(getline(sstr, res,' '))
  {
    if(ms.find(res)==ms.end())
      temp+=res+" ";
    ms[res]=true;
  }
  
  if(str.empty())
    return "";
  
  temp.pop_back();
  return temp;
}

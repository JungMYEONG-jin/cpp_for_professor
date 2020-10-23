#include <string>
#include <sstream>
#include <map>

using namespace std;
std::string alphabetized(const std::string& str){
  //your code here
  stringstream sstr(str);
  string res="";
  map<char, string> result;
  for(auto i : str)
  {
    if(isalpha(i))
    {
      result[tolower(i)]+=i;
    }
    else
      continue;
  }
  
  
  for(auto it : result)
    res+=it.second;
  
  
  
  return res;
  
  
  
  
}

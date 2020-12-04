#include <string>
using namespace std;
std::string string_expansion(const std::string& s) {
  // Insert clever code
  
  
  if(s.empty())
    return "";
  
  
  string res;
  
  
  bool num = false;
  int count = 0;
  for(int i=0;i<s.size();i++)
  {
    if(isdigit(s[i]))
      {num = true;
       count = s[i]-'0';
       }
    
    if(num && isalpha(s[i]))
    {
      res+=string(count, s[i]);
    }else if(!num && isalpha(s[i]))
      res+=s[i];
    
    
  }
  
  
  
  return res;
  
}

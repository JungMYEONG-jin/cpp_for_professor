#include <string>

bool isAnagram(std::string t, std::string o){

 if(t.size() != o.size())
  return false;
  
  std::transform(t.begin(),t.end(),t.begin(),::tolower);
  std::transform(o.begin(),o.end(),o.begin(),::tolower);
  std::sort(t.begin(),t.end());
  std::sort(o.begin(),o.end());
  
  return t==o;
  
}

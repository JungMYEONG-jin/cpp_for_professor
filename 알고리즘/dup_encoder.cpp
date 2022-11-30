#include <string>
#include <map>

using namespace std;


std::string duplicate_encoder(const std::string& word){
  
  if(word.empty())
    return {};
  
  
  map<char, int> res;
  
  for(auto i : word)
  {
    if(isalpha(i))
      res[tolower(i)]++;
    else
      res[i]++;
  }
  
  string result="";
  
  for(auto i : word)
  {
      if(isalpha(i))
      {
        if(res[tolower(i)]>1)
          result+=")";
        else
          result+="(";
      }
    else
      {
      
      if(res[i]>1)
        result+=")";
      else
        result+="(";
      
    }
  }
  
  
  return result;
}

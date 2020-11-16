using namespace std;

bool solve(std::string a, std::string b){  
    //..
  
  
    
  
 
    auto it = a.find('*');
    
    if(it == a.npos)
    {
      if(a==b)
        return true;
      return false;
    }
  
  
    string k = a.substr(0,it);
    string c = b.substr(0, it);
    if(k!=c)
      return false;
  cout<<it<<endl;
    // same case then check right only
    if(it+1==a.size())
      return true;
  string left= a.substr(it+1);
  
  string right = b.substr(it);
  cout<<left<<" "<<right<<endl;
  if(right.find(left)!=right.npos && a[a.size()-1]==b[b.size()-1])
    return true;
  return false;
    
  
   
}

/* SIMPLE CODE

#include <string>
#include <fnmatch.h>

bool solve(const std::string& a, const std::string& b) { 
  return fnmatch(a.c_str(), b.c_str(), 0) == 0;
}




*/

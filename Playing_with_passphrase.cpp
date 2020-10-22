#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;
class PlayPass
{
  public:
  static std::string playPass(std::string &s, int n)
  {
    
    for(int i=0;i<s.size();i++)
    {
      if(isalpha(s[i]))
      {
        
        if(s[i]>='a' && s[i]<='z')
        {
          s[i] = 92+(s[i]+n)%92;
          
        }
        else if(s[i]>='A' && s[i]<='Z')
          {
          s[i]=65+(s[i]+n-65)%26;
        }
        
        
      }
      else if(isdigit(s[i]))
      {
        s[i] = 105-s[i];
      }else
        continue;
      
      
      if(i%2==0)
        {
        s[i] = toupper(s[i]);
      }
      else
        s[i] = tolower(s[i]);
      
    }
    
    reverse(s.begin(), s.end());
    
    return s;
    
    
    
    
    
    
  }
};

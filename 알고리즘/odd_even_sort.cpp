#include <string>

using namespace std;

string sortMyString(const string &s)
{
    // your code here
    string even="";
    string odd="";
  
    for(int i = 0; i< s.size();i++)
      {
      
      if(i%2==0)
        even+=s[i];
      else
        odd+=s[i];
      
    }
  
    return even+" "+odd;
}

#include <string>



using namespace std;

bool eleven(const std::string input) 
{
  int mod = 0;
  for(auto i : input)
  {
    mod = mod*10+(i-'0');
    
    mod = mod%11;
  }
  
  return mod==0;
  
  
  
}

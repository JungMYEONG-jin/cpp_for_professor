#include <string>
#include <vector>

using namespace std;



std::string tickets(const std::vector<int>& peopleInLine) {
  // your code here
  int sum25=0;
  int sum50=0;
  int sum100=0;
  
  if(peopleInLine.empty())
    return "YES";
  
  for(auto i : peopleInLine)
  {
    if(i==25)
    {
      sum25++;
    }
    else if(i==50)
    {
      if(sum25>=1)
        {
        sum25--;
        sum50++;
          }
      else
        return "NO";
    }else if(i==100)
    {
      if(sum25>=1 && sum50>=1)
      {
        sum25--;
        sum50--;
        sum100++;
      }
      else if(sum25>=3)
      {
        sum25-=3;
       
        sum100++;
      }
      else
        return "NO";
    }
    
    
  }
  return "YES";
}

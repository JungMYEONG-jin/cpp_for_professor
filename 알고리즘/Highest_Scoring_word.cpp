#include <string>
#include <map>
#include <sstream>

using namespace std;


std::string highestScoringWord(const std::string &str)
{
  map<char, int> res;
  int j=1;
  for(auto i ='a';i<='z';i++)
    res[i]=j++;
  
  
  stringstream sstr(str);
  
  string temp="";
 string re;
  int sum=0;
  int max=0;
  while(getline(sstr, temp, ' '))
  {
    
    for(auto i : temp)
      sum+=res[i];
    if(max<sum)
    {
      max=sum;
      re=temp;
    }
    sum=0;
  }
  
  
  
  
  
  return re;
}

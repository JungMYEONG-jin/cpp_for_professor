#include <sstream>
#include <algorithm>
using namespace std;
std::string watchPyramidFromTheSide(std::string characters)
{
   if(characters.empty())
      return "";
  string res;
  int n = 2*characters.size()-1;
  
  reverse(characters.begin(),characters.end() );
  int j=0;
  for(int i=1;i<=2*characters.size()-1;i+=2, j++)
  {
    res+=string((n-i)/2, ' ')+string(i,characters[j])+string((n-i)/2, ' ')+"\n";
    
  }
  
    
  res.pop_back();
  
  return res;
}

std::string watchPyramidFromAbove(std::string characters)
{
    if(characters.empty())
      return "";
  
  
    int n = characters.size()*2-1;
    int size= characters.size();
    vector<string> res;
    for(int i=0;i<size;i++)
    {
      string k = characters.substr(0,i)+string(characters.substr(i).size(),characters[i]);
      string r = k;
      k.pop_back();
      reverse(k.begin(), k.end());
      r+=k;
      res.push_back(r);
      
    }
  
  string result;
  for(auto i : res)
    result+=i+"\n";
  
  res.pop_back();
  reverse(res.begin(), res.end());
  
   for(auto i : res)
    result+=i+"\n";
  
  result.pop_back();
  return result;
  
    
}

int countVisibleCharactersOfThePyramid(std::string characters)
{
  
  if(characters.empty())
    return -1;
  
   int n = characters.size()*2-1;
  return n*n;
}

int countAllCharactersOfThePyramid(std::string characters)
{
  if(characters.empty())
    return -1;
  int n = characters.size()*2-1;
  int sum=0;
  for(int i=1;i<=n;i+=2)
  {
    sum+=i*i;
  }
 return sum;
}

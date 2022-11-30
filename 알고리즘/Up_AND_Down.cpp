#include <vector>
#include <string>
#include <sstream>

using namespace std;

string low(string k)
{
  for(int i=0;i<k.size();i++)
    k[i]=tolower(k[i]);
  return k;
}

string upper(string k)
{
  for(int i=0;i<k.size();i++)
    k[i]=toupper(k[i]);
  return k;
}


class UpAndDown
{
public:
    static std::string arrange(const std::string &strng)
    {
      if(strng.empty())
        return "";
      
      vector<string> res;
      stringstream sstr(strng);
      string temp;
      
      while(getline(sstr, temp, ' '))
        res.push_back(temp);
   
      for(int i=1;i<res.size();i+=2)
      {
        if(res[i].size()<res[i-1].size())
        {
          swap(res[i], res[i-1]);
          if(i+1<res.size() && res[i].size()<res[i+1].size())
            swap(res[i], res[i+1]);
        }
        else if(i+1< res.size() && res[i].size()<res[i+1].size())
        {
          swap(res[i], res[i+1]);
          if(res[i].size()<res[i-1].size())
            swap(res[i], res[i-1]);
        }
        
      }
     
      
      
      string k="";
      for(int i=0;i<res.size();i++)
      {
        if((i+1)%2==0)
          k+=upper(res[i])+" ";
        else
          k+=low(res[i])+" ";
      }
      k.pop_back();
      return k;
    }
};

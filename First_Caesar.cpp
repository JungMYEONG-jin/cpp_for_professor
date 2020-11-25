#include <vector>
#include <iomanip>
using namespace std;

class CaesarCipher
{
  public:
    static std::vector<std::string> movingShift(const std::string &s, int shift)
    {
      int n = 0;
      if(s.size()%5==0)
        n = s.size()/5;
      else
        n=s.size()/5+1;
      string k = s;
      
      
      vector<string> res;
      string temp;
      temp.reserve(n);
      for(int i = 0;i<k.size();i++)
      {
        if(isalpha(k[i]) && isupper(k[i]))
        {
          temp+='A'+(k[i]-'A'+shift)%26;
          shift++;
        }else if(isalpha(s[i]) && islower(s[i]))
        {
          temp+='a'+(k[i]-'a'+shift)%26;
          shift++;
        }else
          {
          temp+=k[i];
          shift++;
        }
        
        if(temp.size()==n)
        {
          res.push_back(temp);
          temp.clear();
        }
      
        
      }
      if(res.size()!=5)
      {
        res.push_back(temp);
      }
      
      if(res.size()!=5)
      {
        while(res.size()<5)
          {
          res.push_back("");
        }
      }
      for(auto i : res)
        cout<<i<<endl;
      return res;
      
      
    }
    static std::string demovingShift(std::vector<std::string> &s, int shift)
    {
      
      string res;
      for(auto& i : s)
      {
        for(int j=0;j<i.size();j++)
        {
          
          if(isalpha(i[j]) && isupper(i[j]))
          {
            if(shift==26)
              shift=0;
            res+='A'+(i[j]-'A'+26-shift)%26;
            shift++;
          }else if(isalpha(i[j]) && islower(i[j]))
          {
             if(shift==26)
              shift=0;
            res+='a'+(i[j]-'a'+26-shift)%26;
            shift++;
          }else
            {
            if(shift==26)
              shift=0;
            res+=i[j];
            shift++;
          }
          
          
        }
      
      }
      
      return res;
      
      
    }
};

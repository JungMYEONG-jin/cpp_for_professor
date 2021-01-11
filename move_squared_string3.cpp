#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

class Opstrings3
{
public:
    static std::string diag1Sym(const std::string &strng)
    {
      vector<string> res;
      stringstream sstr(strng);
      string temp;
      while(getline(sstr, temp, '\n'))
      {
        res.push_back(temp);
         
      }
      string fin;
      for(int i=0;i<res.size();i++)
      {
        for(int j=0, len=res.size();j<len;j++)
        {
          fin+=res[j][i];
          if(j==len-1)
            fin+="\n";
        }
      }
      fin.pop_back();
      return fin;
    
    }
    static std::string rot90Clock(const std::string &strng)
    {
      string temp = diag1Sym(strng);
      stringstream sstr(temp);
      string fin;
      string res;
      while(getline(sstr, fin, '\n'))
      {
        reverse(fin.begin(), fin.end());
        res+=fin+"\n";
      }
      res.pop_back();
      return res;
      
    }
    static std::string selfieAndDiag1(const std::string &strng)
    {
      string diag = diag1Sym(strng);
     
      
      vector<string> res;
      vector<string> res2;
      stringstream sstr(diag);
      stringstream sstr2(strng);
      string temp;
      while(getline(sstr, temp, '\n'))
      {
        res.push_back(temp);
      }
      while(getline(sstr2, temp, '\n'))
      {
        res2.push_back(temp);
      }
      string result;
      for(int i=0, len=res.size();i<len;i++)
      {
        result+=res2[i]+"|"+res[i]+"\n";
      }
      result.pop_back();
      return result;
      
      
    }
    // ... complete oper
    static std::string oper(function<string (string)> f, const std::string &s)
    {
      return f(s);
    }
};

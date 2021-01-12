#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Opstrings4
{
public:
    static std::string diag2Sym(const std::string &strng)
      {
      string temp = strng;
      stringstream sstr(temp);
      string res;
      vector<string> test;
      while(getline(sstr, res, '\n'))
        test.push_back(res);
      
      int len = test.size();
      int len2 = test[0].size();
      string result;
      for(int i=len-1;i>=0;i--)
        {
        for(int j=len2-1;j>=0;j--)
          {
          result+=test[j][i];
        }
        result+="\n";
      }
      result.pop_back();
      return result;
      
      
    }
    static std::string rot90Counter(const std::string &strng)
      {
      string temp = diag2Sym(strng);
      string res;
      string fin;
      stringstream sstr(temp);
      while(getline(sstr, res, '\n'))
       {
        reverse(res.begin(), res.end());
        fin+=res+"\n";
      }
      fin.pop_back();
      return fin;
    }
    static std::string selfieDiag2Counterclock(const std::string &strng)
    {
      string temp = strng;
      string diag = diag2Sym(temp);
      string clock = rot90Counter(temp);
      
      
      vector<string> res;
      vector<string> res2;
      vector<string> res3;
      
      stringstream sstr(temp);
      stringstream sstr2(diag);
      stringstream sstr3(clock);
      
      string test;
      
      while(getline(sstr, test, '\n'))
        res.push_back(test);
      while(getline(sstr2, test, '\n'))
        res2.push_back(test);
      while(getline(sstr3, test, '\n'))
        res3.push_back(test);
      
      test.clear();
      
      for(int i=0,len=res.size();i<len;i++)
      {
        test+=res[i]+"|"+res2[i]+"|"+res3[i]+"\n";
      }
      
      test.pop_back();
      return test;
      
      
    }
    // your function oper...
    static std::string oper(function<string (string)> f, const std::string &s)
      {
      return f(s);
    }
};

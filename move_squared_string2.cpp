#include <algorithm>
#include <sstream>


using namespace std;

class Opstrings1
{
public:
    static std::string rot(const std::string &strng)
    {
      string temp = strng;
      reverse(temp.begin(), temp.end());
      return temp;
      
      
      
    }
    static std::string selfieAndRot(const std::string &strng)
    {
      string temp = rot(strng);
      
      int count=0;
      for(auto i : temp)
      {
        if(i!='\n')
          count++;
        else
          break;
        
      }
      string fin;
      stringstream sstr(strng);
      string res;
      while(getline(sstr, res, '\n'))
      {
        fin+=res+string(count, '.')+"\n";
      }
      
      stringstream sstr2(temp);
      res.clear();
      while(getline(sstr2, res, '\n'))
      {
        fin+=string(count, '.')+res+"\n";
      }
      
      fin.pop_back();
      return fin;
      
    }
    // ... complete oper
    static std::string oper(string (func)(const string&), const std::string &s)
      {
      
      return func(s);
    }
};

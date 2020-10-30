#include <sstream>
#include <iomanip>
using namespace std;


std::string pig_it(std::string str)
{
    // Code here
  
  stringstream sstr(str);
  
  string res;
  string temp;
  
  while(getline(sstr, temp, ' '))
  {
    if(temp.size()>=2)
      res+=temp.substr(1)+temp[0]+"ay ";
    else if(!isdigit(temp[0]) && !isalpha(temp[0]))
      res+=temp+" ";
    else
      res+=temp+"ay ";
  }
 
  res.pop_back();
  return res;
  
}

/*
BEST CODE

#include <string>
#include <regex>
using namespace std;
string pig_it(string Z) {
    regex reg(("(\\w)(\\w*)(\\s|$)"));
    return regex_replace(Z, reg, "$2$1ay$3");
}


*/

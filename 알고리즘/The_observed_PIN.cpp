#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> get_text(string ob)
{
  vector<string> res;
  
  for(auto i: ob)
    res.push_back(string(1,i));
  return res;
  
}

vector<string> comb(vector<string> left, vector<string> right)
{
  
  vector<string> res;
  if(right.empty())
    return left;
  for(int i=0;i<left.size();i++)
  {
    
    for(int j=0;j<right.size();j++)
    {
      res.push_back(left[i]+right[j]);
      
      
    }
  }
  return res;
  
}



std::vector<std::string> get_pins(std::string observed) {
  
  if(observed.empty())
    return {};
  
  
  map<char, string> check;
  
  check['0']="08";
  check['1']="124";
  check['2']="1235";
  check['3']="236";
  check['4']="1457";
  check['5']="24568";
  check['6']="3569";
  check['7']="478";
  check['8']="05789";
  check['9']="689";
  

  vector<string> pass = get_text(check[observed[0]]);
  if(observed.size()==1)
    return pass;
  else
    {
    auto res = pass;
    for(int i=1;i<observed.size();i++)
    {
      res = comb(res, get_text(check[observed[i]]));
    }
    
    
    return res;
  }
  
  
  return {};
  }
  
  
  
  /* BEST CODE
  
  
  using namespace std;

vector<string> get_pins(const string &observed, const string &prefix = "")
{
    static const map<char, string> neighbors =
    {
        {'1', "124"},  {'2', "1235"},  {'3', "236"},
        {'4', "1457"}, {'5', "24568"}, {'6', "3569"},
        {'7', "478"},  {'8', "05789"}, {'9', "689"},
                       {'0', "08"}
    };
    if ( !observed.size() ) return {prefix};
    vector<string> pins;
    for (auto c : neighbors.at(observed[0]))
        for (auto pin : get_pins(observed.substr(1), prefix + c))
            pins.push_back(pin);
    return pins;
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  */
  
  
  
  
  
  
  

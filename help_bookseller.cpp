#include <map>
#include <algorithm>
using namespace std;

class StockList
{
public:
  static std::string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories)
    {
    
    
      if (lstOfArt.empty() || categories.empty())
        return "";

    
    
   map<char, int> res;
    for (auto i : lstOfArt)
    {
        auto pos = i.find(' ');
        
        res[i[0]] += stoi(i.substr(pos+1));
    }

    for (auto i : res)
        cout << i.first << " " << i.second << endl;


    string result = "";
    for (auto i : categories)
    {
     
        result += "(" + i + " : " + to_string(res[i[0]]) + ") - ";
       
    }

    
 
    result.pop_back();
    result.pop_back();
    result.pop_back();

    return result;


    
    
  }
};

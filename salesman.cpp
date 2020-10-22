#include <string>
#include <regex>
#include <vector>


using namespace std;

class SalesmanTravel
{
public:
    static std::string travel(const std::string& orgr, std::string zipcode)
      {
      
      vector<string> full;
      
      auto it = find(orgr.begin(), orgr.end(), ',');
      auto prev = orgr.begin();
      do{
        full.emplace_back(prev, it);
        prev = ++it;
        it =  find(it, orgr.end(), ',');
        
      }while(it!=orgr.end());
      
      
      string numbers;
      string add;
      regex zip("(\\d+)\\s(.+)\\s+"+zipcode+"$");
      
      smatch match;
      
      for(auto& i : full)
        {
        if(regex_match(i, match, zip) && match.size()==3)
          {
          add+=(add.empty()?"":",")+match[2].str();
          numbers+=(numbers.empty()?"":",")+match[1].str();
        }
      }
      
      return zipcode+":"+add+"/"+numbers;
    }
};

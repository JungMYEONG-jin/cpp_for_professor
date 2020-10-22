#include <algorithm>
#include <string>

using namespace std;

class TwoToOne
{
public:
    static std::string longest(const std::string &s1, const std::string &s2);
};

string TwoToOne::longest(const std::string &s1, const std::string& s2)
  {
  string i= s1+s2;
  
  sort(i.begin(), i.end());
  
  i.erase(unique(i.begin(), i.end()), i.end());
  return i;
  
  
  
}

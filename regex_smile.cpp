#include <regex>
using namespace std;

int countSmileys(std::vector<std::string> arr)
{
  regex re("^[:;][-~]?[)D]");
  
  
  int count=0;
  for(auto i : arr)
  {
    smatch match;
    if(regex_match(i, match, re))
      count++;
  }
  return count;
}

#include <string>
#include <regex>

int solve(std::string s)
{
  int number = -1;
  std::regex reg("[[:digit:]]+");
  for(auto it = std::sregex_iterator(s.begin(), s.end(), reg); it != std::sregex_iterator(); ++it)
  {
    int n = std::stoi((*it).str());
    number = n > number ? n : number;
  }
  return number;
}

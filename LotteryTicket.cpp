include <algorithm>
using namespace std;
std::string bingo(std::vector<std::pair<std::string, int>> ticket, int win)
{
int pos=0;

  for(auto i : ticket)
   {
    char b = i.second;
    if(i.first.find(b)!=i.first.npos)
      pos++;
  }
  
  
  
  
  
  
  return pos>=win?"Winner!":"Loser!";
}

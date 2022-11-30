#include<string>
#include <algorithm>
#include <map>
using namespace std;
bool scramble(const std::string& s1, const std::string& s2){
  //your code here
  map<char, int> res1;
  map<char, int> res2;
  for(auto i : s1)
    res1[i]++;
  for(auto i : s2)
    res2[i]++;
  
  for(auto it : s2)
  {
    if(res1[it]==0 || res1[it]<res2[it])
      return false;
  }
  return true;
}

/* BEST CODE
#include <algorithm>
#include <string>

bool scramble(std::string s1, std::string s2) {
  std::sort(begin(s1), end(s1));
  std::sort(begin(s2), end(s2));
  return std::includes(begin(s1), end(s1), begin(s2), end(s2));
}




*/

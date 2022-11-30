#include <string>
#include <algorithm>
using namespace std;
int solve(const std::string& s)
{
  
    string res="";
    int sum=0;
    string k = s;
    map<char, int> score;
    int j=1;
    for(auto ch ='a';ch<='z';ch++)
      score[ch]=j++;
    string conso = "aeiou";
  vector<int> rank;
    for(auto i : k)
    {
      if(find(conso.begin(), conso.end(), i)==conso.end())
        {
        
        sum+=score[i];
      }else
      {
        rank.push_back(sum);
        sum=0;
      }
      
      
      
    }
  
  
  rank.push_back(sum);
  return *max_element(rank.begin(), rank.end());
   
}

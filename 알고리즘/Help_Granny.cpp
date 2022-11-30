#include <unordered_map>
#include <vector>
#include <cmath>


using namespace std;

typedef std::unordered_map<std::string, double> stringdblmap;
class Tour
{
public:
    static int tour(std::vector<std::string> &arrFriends, std::vector<std::vector<std::string>> &ftwns, stringdblmap &h)
    {
      
      
      map<string, string> res;
      for(auto& it : ftwns)
      {
        
        auto its = find(arrFriends.begin(), arrFriends.end(), it[0]);
        if(its!=arrFriends.end())
          res[it[0]] =it[1];        
        
      }
      
      for(auto it : res)
        cout<<it.first<<" "<<it.second<<endl;
      
      // res는 존재하는 친구 타운 테이블임
      
      
      double dist=0;
      double prev=0;
      //res에 친구들 타운이 기록됨
      // first 친구이름 second 마을
      for(auto it : res)
      {
        double d = h[it.second];
        if(dist==0)
        {
          dist+=d;
          prev=d;
          
        }
        else
        {
          dist+=sqrt(d*d-prev*prev);
          prev=d;
        }
        
        
        
      }
      auto it = max_element(res.begin(), res.end());
      dist+=h[it->second];
      
      return dist;
      
      
      
      
    }
};

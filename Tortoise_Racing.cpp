#include <cmath>
#include <vector>

using namespace std;
class Tortoise
{
public:
    static std::vector<int> race(int v1, int v2, int g)
    {
      
      if (v1 > v2)
    return { -1,-1,-1 };



       auto time = g * 3600 / (v2 - v1);
       auto hour = time / 3600;
       auto min = (time % 3600) / 60;
       auto  sec = time % 60;
  

  return { hour, min, sec };
      
      
    }
};

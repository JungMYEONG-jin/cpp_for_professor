#include <vector>
#include <map>
#include <algorithm>


using namespace std;


vector<string> tens = { "", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
      "eighty", "ninety" };
vector<string> nums = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
      "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
      "nineteen" };


string convert(int n) {
    if (n == 0)
      return "zero";
    string result;
    if (n % 100 <20) {
      result = nums[n % 100];
      n /= 100;
    } else {
      result = nums[n % 10];
      n /= 10;
      result = tens[n % 10] + result;
      n /= 10;
    }
    if (n == 0)
      return result;
    return nums[n] + " hundred" + result;

}


class Dinglemouse
{
public:
    static vector<int> sort(const vector<int> &array)
    {
      vector<pair<string, int>> res;
      vector<int> result;
      
      for(auto i : array)
        {
        res.push_back(make_pair(convert(i),i));
        
      }
      
      std::sort(res.begin(), res.end(), [](auto e, auto k){return e.first<k.first;});
      
      for(auto it : res)
        result.push_back(it.second);
      
      return result;
      
    }
};

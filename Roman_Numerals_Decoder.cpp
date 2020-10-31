#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(string roman) {
  // Your code here
unordered_map<char, int> romans{ {'M',1000}, {'D', 500},{'C', 100},{'L', 50}, {'X', 10}, {'V', 5}, {'I', 1} };
  int sum = 0;
  int prev = 0;
  reverse(roman.begin(), roman.end());
  for (auto i : roman)
  {
    int val = romans[i];
    sum += (val < prev) ? -val : val;
    prev = val;
  }
  return sum;
}


/*  BEST CODE

#include <iostream>
#include <string>

using namespace std;

map<char, int> nums = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};

int solution(string roman) {
      int res = 0;
      int old = 0;
      
      for(auto a : roman){
          int curr = nums[a];
          res += curr;
          
          if(curr > old){
              res -= 2 * old;
          }
          
          old = curr;
      }
      
      
      return res;
}





*/

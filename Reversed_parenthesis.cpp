#include <stack>

using namespace std;

int solve(std::string s){
    //..
  
  // check it odd? odd can not be balanced
  if(s.size()%2)
    return -1;
  stack<char> res;
  for(auto i : s)
  {
    if(i==')' && !res.empty())
    {
      if(res.top()=='(')
      {
        res.pop();
      }else
        res.push(i);
    }else
      res.push(i);
  }
  
  int len = res.size();
  
  
  int count=0;
  while(!res.empty() && res.top()=='(')
  {
    res.pop();
    count++;
  }
  
  return len/2+count%2;
  
  
}

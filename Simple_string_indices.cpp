#include <string>
using namespace std;
int solve(std::string str, int index){
  //your code here
  
  if(str[index]!='(')
    return -1;
  int open=1;
  for(int i=index+1;i<str.size();i++)
  {
    if(str[i]=='(')
      open++;
    else if(str[i]==')' && open>0)
      open--;
    
    if(open==0)
      return i;
    
    
    
  }
  
  return -1;
  
}

#include <set>

using namespace std;

bool validSolution(unsigned int board[9][9]){
  /* Write your solution here */
   set<int> check{ 1,2,3,4,5,6,7,8,9 };
  
  int count=1;
  int n=3;
  set<int> k;
  for(int i=0;i<n;i++)
  {
    
    for(int j=0;j<n;j++)
      {
      
      k.insert(board[i][j]);
      
      
    }
    count++;
    if(count>n && n<=6)
      {
      n+=3;
      if(check!=k)
        return false;
      else
        k.clear();
       
       }
  }
  
  


  return true;
}

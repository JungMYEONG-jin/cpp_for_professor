#include <string>
using namespace std;

string alphabetWar(string fight)
{ 
  string res;
  for(int i=0;i<fight.size();i++)
  {
    if((i-1>=0&&fight[i-1]=='*') || ( i+1<fight.size()&& fight[i+1]=='*')  || fight[i]=='*')
      continue;
    else
      res+=fight[i];
  }
  
  map<char, int> left;
  map<char, int> right;
  
  left['w']=0; left['p']=0; left['b']=0; left['s']=0;
  right['m']=0;right['q']=0;right['d']=0;right['z']=0;
  
  
  
  for(auto i : res)
  {
    
    if(left.find(i)!=left.end())
    {
      if(i=='w')
        left[i]+=4;
      else if(i=='p')
        left[i]+=3;
      else if(i=='b')
        left[i]+=2;
      else
        left[i]+=1;
    }else if(right.find(i)!=right.end())
    {
      if(i=='m')
        right[i]+=4;
      else if(i=='q')
        right[i]+=3;
      else if(i=='d')
        right[i]+=2;
      else if(i=='z')
        right[i]+=1;
    }
    
    
    
    
  }
  
  
  int l_sum=0;
  int r_sum=0;
  
  for(auto it : left)
    l_sum+=it.second;
  for(auto it : right)
    r_sum+=it.second;
  cout<<fight<<" "<<res<<endl;
  if(l_sum>r_sum)
    return "Left side wins!";
  else if(l_sum<r_sum)
    return "Right side wins!";
  
  return "Let's fight again!";
  
  
  
  
  
}

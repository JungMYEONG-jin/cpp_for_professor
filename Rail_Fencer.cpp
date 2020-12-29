#include <string>
using namespace std;
std::string encode_rail_fence_cipher(const std::string &str, int n) {
  
  if(str.empty())
    return str;
  
  char test[n][str.size()];
  
  for(int i=0;i<n;i++)
  {
    for(int j=0, len = str.size();j<len;j++)
      test[i][j]='\n';
  }
  
  // after init 
  
  bool direc = false;
  string res;
  int row=0;
  int col=0;
 
    for(int j=0, len=str.size();j<len;j++)
    {
      
      if(row==0 || row==n-1)
        direc=!direc;
      
      test[row][col++] = str[j];
      
      direc?row++:row--;
      
      
    }
  
  
   for(int i=0;i<n;i++)
  {
    for(int j=0, len=str.size();j<len;j++)
    {
      
      if(test[i][j]!='\n')
        res.push_back(test[i][j]);
      
      }
     
     }
  
  
  return res;
}

std::string decode_rail_fence_cipher(const std::string &str, int n) {
  
  
  if(str.empty())
    return str;
  
  int len = str.size();
  
  char test[n][len];
  
  bool visit[n][len];
  
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<len;j++)
      test[i][j]='\n';
  }
   for(int i=0;i<n;i++)
  {
    for(int j=0;j<len;j++)
      visit[i][j]=false;
  }
  
  int row = 0, col=0;
  bool direc=false;
  
  
  for(int j=0;j<len;j++)
  {
    if(row==0)
      direc = true;
    
    if(row==n-1)
      direc =false;
    
    
    //test[row][col++]='*'; // mark pos
    visit[row][col++]=true;
    
    direc?row++:row--;
  }
  
  
  int idx=0;
  string res;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<len;j++)
    {
      
      if(visit[i][j]==true && idx<len)
        test[i][j]=str[idx++];
      
      
      
    }
  }
  
  row=0, col=0;
  direc = false;
  for(int i=0;i<len;i++)
  {
    if(row==0)
      direc=true;
    if(row==n-1)
      direc=false;
    
    
    res.push_back(test[row][col++]);
    
    direc?row++:row--;
    cout<<res<<endl;
  }
 
  return res;
}

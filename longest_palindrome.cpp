#include <bits/stdc++.h> 

using namespace std;
// MY CODE
int longest_palindrome2(const std::string &s)
{
  if(s.empty())
    return 0;
  if(s.size()==1)
    return 1;
  int n = s.size();
  bool table[n][n];
  
  memset(table, 0, sizeof(table));
  
  for(int i=0;i<n;i++)
    table[i][i]=true;
  int start=0;
  int maxlen=1;

    for(int i=0;i<n-1;i++)
    {
      if(s[i]==s[i+1])
      {
        table[i][i+1]=true;
        start=i;
        maxlen=2;
      }
    }

    // greater or equal than len 3
    
    
    for(int k=3;k<=n;k++)
    {
      for(int i=0;i<n-k+1;i++)
      {
        int j= i+k-1;
        if(table[i+1][j-1] && s[i]==s[j])
        {
          table[i][j]=true;
        if(k>maxlen)
        {
          start=i;
          maxlen=k;
        }
        }
        
      
        
      }
    }
    
  return maxlen;
  
}


// BEST CODE


#include <algorithm>
int longest_palindrome(const std::string &s)
{
    int maxlen = 0;
    for ( int i = 0; i < s.size(); ++i )
    for ( int j = 0; j < s.size(); ++j )
    {
      std::string sub = s.substr(i, s.size()-j);
      std::string rev = sub;
      std::reverse ( rev.begin(), rev.end());
      
      if ( sub == rev )
        maxlen = sub.size() > maxlen ? sub.size() : maxlen;
    }
    
    
    return maxlen;
}


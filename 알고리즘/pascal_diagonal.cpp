#include <vector>

using namespace std;



vector<vector<unsigned long long>> get_pascal(long n)
{
  
  vector<vector<unsigned long long>> res;
  
  for(int i=0;i<n;i++)
  { 
    long long num =1;
    vector<unsigned long long> temp;
    for(int j=0;j<i+1;j++)
    {
      temp.push_back(num);
      
      num = (num*(i-j))/(j+1);
    }
    res.push_back(temp);
  }
  return res;


}


typedef unsigned long long ull;
class Diagonal
{
public:
    static ull diagonal(int n, int p)
      {
      auto pas = get_pascal(n+1);
      ull sum = 0;
      for(auto it : pas)
      {
        if(it.size()>p)
          sum+=it[p];
        
      }
      
      return sum;
      
    }
};


// BEST Solutuon


typedef unsigned long long ull;
class Diagonal
{
public:

    static ull binorm(int n, int p)
    {
      return (n+1-p)*binorm(n,p-1)/p;
    
    
    }


    static ull diagonal(int n, int p)
      {
     return binorm(n,p)*(n+1)/(p+1);
      
    }
};







//

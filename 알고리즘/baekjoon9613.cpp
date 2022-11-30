/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;


long long gcd(long long a, long long b)
{
    while(b!=0)
    {
        long long c= a%b;
        a=b;
        b=c;
    }
    return a;
}


int main()
{
  int T;
  cin>>T;
  
  int num;
  vector<int> res(100);
  for(int i=0;i<T;i++)
  {
      
      cin>>num;
      for(int i=0;i<num;i++)
        cin>>res[i];
    
       long sum=0;
       for(int i=0;i<num;i++)
       {
           for(int j=i+1;j<num;j++)
            {
                sum+=gcd(res[i], res[j]);
            }
       }
       cout<<sum<<'\n';
      
      
      
  }
  return 0;
}


/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <set>


using namespace std;



int main()
{
   int T;
   cin>>T;
   int res[T+1];
   res[0]=0;
   
   for(int i=1;i<=T;i++)
    res[i]=i;
    
    for(int i=1;i<=T;i++)
    {
        for(int j=1;j<=sqrt(i);j++)
        {
            res[i] = min(res[i], res[i-j*j]+1);
        }
    }
    
    
   cout<<res[T]<<endl;
  
}

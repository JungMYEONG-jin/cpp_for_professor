/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;



int main()
{
    long num;
    bool flag=false;
    
    long prime[1000005];
   fill(prime, prime+1000005, 1);

    for(int i=3;i*i<=1000000;i+=2)
    {
      if(prime[i]==1)
       {
 	for(int j=i*i;j<=1000000;j+=i)
            {
               prime[j] = 0;
            }

      }


    }
    
    
    
    
   while(1)
   {
       scanf("%d", &num);
       flag = false;
       if(num==0)
       {
           break;
       }
       
       for(long i=3;i<num;i+=2)
       {
          
           if(prime[i] && prime[num-i])
           {
               flag =true;
               cout<<num<<" = "<<i<<" + "<<num-i<<'\n';
               break;
               
           }
       }
       if(!flag)
       {
           cout<<"Goldbach's conjecture is wrong.\n";
       }
       
       
       
       
   }
}

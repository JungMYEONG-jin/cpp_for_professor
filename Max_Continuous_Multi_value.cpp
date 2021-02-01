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
#include <iomanip>



using namespace std;



int main()
{
   int T;
   cin>>T;
   double res[10001];
   double temp=0.0;
   
   for(int i=2;i<=T;i++)
   {
       if(res[i]*res-1]>=res[i])
        {
            res[i]=res[i]*res[i-1];
        }
        
        temp = max(temp, res[i]);
   }
    
    
   cout<<fixed<<setprecision(3)<<temp<<endl;
}

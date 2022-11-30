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

int main()
{
    int n;
    int min=101;
    int sum=0;
    for(int i=0;i<7;i++)
    {
        cin>>n;
        sum+=n%2==1?n:0;
        min=(n%2==1 && min>n)?n:min;
    }
    if(sum!=0)
    {
        cout<<sum<<'\n'<<min;
    }else
        cout<<-1<<'\n';
}


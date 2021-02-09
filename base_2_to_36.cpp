/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <map>
#include <cmath>
#include <string>

using namespace std;

void createMap(map<char, int>* m)
{
    (*m)['0']=0;(*m)['1']=1;(*m)['2']=2;(*m)['3']=3;
    (*m)['4']=4;(*m)['5']=5;(*m)['6']=6;(*m)['7']=7;
    (*m)['8']=8;(*m)['9']=9;
    int num=10;
    for(auto i = 'A';i<='Z';i++)
    {
        (*m)[i]=num++;
    }
}


int transform_to_decimal(int base, string k)
{
    int sum=0;
    map<char, int> m;
    createMap(&m);
    for(int i=0, len=k.size();i<len;i++)
    {
        sum+=pow(base, len-i-1)*m[k[i]];
    }
    
    return sum;
}







int main()
{
   string k; int base;
   cin>>k>>base;
   cout<<transform_to_decimal(base, k)<<endl;

    return 0;
}

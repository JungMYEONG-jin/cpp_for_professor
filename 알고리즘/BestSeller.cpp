/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;


int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   int n;
   cin>>n;
   
   map<string, int> res;
   
   
   string k;
   
   for(int i=0;i<n;i++)
   {
       cin>>k;
       res[k]++;
   }
   
   cout<<max_element(res.begin(), res.end(), [](auto e, auto k){return e.second<k.second;})->first<<'\n';
   
   
   
    return 0;
}

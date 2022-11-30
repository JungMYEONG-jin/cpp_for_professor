/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    string str;
    string res;
    vector<string> vec(n);
    for(int i=0;i<n;i++)
    {
       cin>>vec[i];
        
    }
    
    int sum=0;
    map<string, int> temp;
    for(int i=0;i<m;i++)
    {
        cin>>str;
       temp[str]++;
        
    }
    
   for(auto& it : vec)
   {
       if(temp[it])
        {
            sum+=temp[it];
        }
   }
    
    
    
    cout<<sum<<endl;
    
}

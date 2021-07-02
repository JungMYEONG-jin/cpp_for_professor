/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>


using namespace std;


int main()
{
    string x, y;
    cin>>x>>y;
    
    int len1 = x.size();
    int len2 = y.size();
    
    vector<vector<int>> res(len1+1, vector<int>(len2+1));
    
    for(int i=0;i<=len1;i++)
        res[i][0] = i;
    for(int j=0;j<=len2;j++)
        res[0][j]=j;
        
    res[0][0]=0;
    
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            
            int pen = 0;
            if(x[i-1]!=y[j-1])
                pen=1;
            res[i][j] = min(res[i-1][j-1]+pen, min(res[i-1][j]+1, res[i][j-1]+1));
        }
    }
    
    
    for(auto i : res)
    {
        
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }
        
    
    cout<<res[len1][len2]<<endl;
    

    return 0;
}

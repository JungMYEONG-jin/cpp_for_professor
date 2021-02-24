#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <cmath>


using namespace std;


int cnt = 0;


typedef long long ll;


void flip(vector<string>& a, vector<string>& b, int x, int y)
{
    cnt++;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[x+i][y+j]=='0') a[x+i][y+j]='1';
            else a[x+i][y+j]='0';
        }
    }
}


int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    int n,m;
    cin>>n>>m;
    vector<string> a;
    vector<string> b;
    
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        a.push_back(s);
    }
    
      for(int i=0;i<n;i++)
    {
        cin>>s;
        b.push_back(s);
    }
    
    
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<m-2;j++)
        {
            if(a[i][j]!=b[i][j])
            {
                flip(a, b, i, j);
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]!=b[i][j])
            {
                cout<<-1;
                return 0;
            }
        }
    }
    
    
    cout<<cnt;
    
    
    return 0;
    
    
}


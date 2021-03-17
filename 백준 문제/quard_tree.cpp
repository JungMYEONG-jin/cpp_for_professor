#include <iostream>
#include <string>

using namespace std;


char maps[65][65];

void dfs(int x, int y, int len, string& temp)
{
    if(len==1)
    {
        temp+=string(1, maps[x][y]);
        return ;
    }
    
    bool one=true, zero=true;
    
    for(int i=x;i<x+len;i++)
    {
        for(int j=y;j<y+len;j++)
        {
            if(maps[i][j]=='0') one = false;
            if(maps[i][j]=='1') zero=false;
        }
    }
    
    if(one)
    {
        temp+="1";
        return ;
    }
    
    if(zero)
    {
        temp+="0";
        return;
    }
    
    temp+="(";
    dfs(x,y,len/2, temp);
    dfs(x,y+len/2,len/2, temp);
    dfs(x+len/2,y,len/2, temp);
    dfs(x+len/2,y+len/2,len/2, temp);
    
    
    temp+=")";
    
    
    
}


int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    
    int n;
    string s;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>s;
        for(int j=0;j<n;j++)
        {
            maps[i][j]=s[j];
        }
    }
    
    
    s="";
    dfs(0,0,n,s);
    
    
    
    
    cout<<s<<endl;
    
    
    
}

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <regex>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <sstream>
#include <functional>

using namespace std;

int leftPtr=0;
int rightPtr=0;

void dfs(string& res, vector<int>& visited, set<string>& temp, int l, int r, int n, string num)
{
    if(rightPtr+1==n)
    {
        temp.insert(num);
    }else
    {
        if(l!=leftPtr && visited[l-1]==0)
        {
            visited[l-1]=1;
            string temps = num;
            num = num+res[l-1]+num;
            dfs(res, visited, temp, l-1, r, n+1, num);
            num = temps;
            visited[l-1]=0;
        }
        
        if(r!=rightPtr && visited[r+1]==0)
        {
            visited[r+1]=1;
            string temps = num;
            num = num+num+res[r+1];
            dfs(res, visited, temp, l, r+1, n+1, num);
            num = temps;
            visited[r+1]=0;
        }
    }
    
    
}









int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.tie(NULL);
    
    string res;
    cin>>res;
    
    int len = res.size();
    rightPtr = len-1;
    vector<int> visited(len, 0);
    
    set<string> temp;
    string num="";
    
    for(int i=0;i<len;i++)
    {
        visited[i]=1;
        num = res[i];
        dfs(res, visited, temp, i, i, 1, num);
        visited[i]=0;
    }
    
    
    cout<<temp.size()<<'\n';
    
    
    
    
    
    
    
    
    
    
}

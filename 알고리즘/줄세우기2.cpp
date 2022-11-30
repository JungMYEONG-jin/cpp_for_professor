#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <cmath>


using namespace std;

typedef long long ll;

int L[1000001] = {0};
int N;
int len;

int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N;
    int val;
    len =0;
    for(ll i=1;i<=N;i++)
    {
        cin>>val;
        L[val] = L[val-1]+1;
        len = max(len, L[val]);
    }
    
    
    cout<<N-len<<'\n';
    
    return 0;
    
    
    
    
    
    
    
    
    
}

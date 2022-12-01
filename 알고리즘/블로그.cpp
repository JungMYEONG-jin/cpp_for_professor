#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <numeric>

#define INF 999999999

using namespace std;

int main()
{
    int n, x;
    cin>>n>>x;
    vector<int> res(n);
    for(int i=0;i<n;i++)
        cin>>res[i];

    int maxVisitor = 0;
    int cnt = 0;
    int cur = 0;
    for(int i=0;i<n-x+1;i++){
        if(i==0)
        {
            for(int i=0;i<x;i++)
                cur+=res[i];
            cnt = 1;
            maxVisitor = cur;
        }else{
            cur = cur - res[i-1] + res[i+x-1];
            if(cur==maxVisitor){
                cnt++;
            }else if(cur>maxVisitor){
                maxVisitor = cur;
                cnt=1;
            }
        }

    }
    if(maxVisitor==0)
        cout<<"SAD";
    else{
        cout<<maxVisitor<<'\n'<<cnt;
    }
}

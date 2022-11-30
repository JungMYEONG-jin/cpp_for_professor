#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<int> res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    int num=0;
    for(int i = n-1;i>0;i--)
    {
        if(res[i]<=res[i-1])
        {
            int k = res[i-1]-res[i]+1;
            res[i-1]-=k;
            num+=k;
        }
    }


    cout<<num<<'\n';
    return 0;


}

#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <functional>

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    
    map<string, int> m;
    int arr[] = {1, 2, 3};
    typedef std::function<void(string, int)> func_t;
    
    func_t dfs = [arr, &m, &dfs, n](string s, int sum){
        for(int i=0;i<3;i++)
        {
            sum+=arr[i];
            if(sum>n)
                continue;
            else if(sum==n)
            {
                m[s+to_string(arr[i])]++; // case sum==n 
            }else
                dfs(s+to_string(arr[i])+"+", sum);
            sum-=arr[i];
        }
    };
    
    dfs("",0);
    if(k>m.size())
    {
        cout<<-1<<endl;
        return 0;
    }
    
    int cnt=1;
    for(const auto& it : m)
    {
        if(cnt==k)
        {
            cout<<it.first<<endl;
            break;
        }
        cnt++;
    }
    
    return 0;
}

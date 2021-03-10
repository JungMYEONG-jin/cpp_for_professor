#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<string, int> res;

    vector<string> temp(n);

    for (int i = 0; i < n; i++)
        cin >> temp[i];

    int left = 0;
    int right = n - 1;
    bool flag;
    int mid = 0;

    while(left<=right)
    {
        mid = (left+right)>>1;
        bool dup = false;
        
        for(int j=0;j<m;j++)
        {
            string str;
            for(int i=mid;i<n;i++)
            {
                str+=temp[i][j];
            }
            
            if(res[str])
            {
                dup = true;
                break;
            }
            
            res[str]++;
        }
        
        if(dup)
        {
            right = mid-1;
        }else
            left = mid+1;
        
        flag = dup;
        
        
    }
    
    
    if(flag)
        cout<<mid-1<<'\n';
    else
        cout<<mid<<'\n';
    
    
    return 0;
}

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
using namespace std;

typedef long long ll;





int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<ll> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stack<pair<int,ll>> res;
    stack<int> idx;
    vector<int> arr2(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int j = i;
        while (!res.empty() && res.top().second < arr[i])
        {
            arr2[res.top().first] = i + 1;
            res.pop();
           
            
        }

        res.push({ i,arr[i] });
    }

    while (!res.empty())
    {
        arr2[res.top().first] = 0;
        res.pop();
    }

    for (auto i : arr2)
        cout << i << " ";

}




// BEST CODE

/*



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.tie(NULL);
    int n;
    cin >> n;
    int x;
    stack<pair<int,long>> res;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        
        while(!res.empty())
        {
            if(x<res.top().second)
            {
                
                cout<<res.top().first<<" ";
                break;
            }
            
            res.pop();
        }
        
        if(res.empty())
            cout<<0<<" "; // 만약 자신보다 큰걸 못찾으면
        
        res.push({i+1, x});
    }
    
    

}






















*/

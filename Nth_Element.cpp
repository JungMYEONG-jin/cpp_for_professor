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
    int k, n;
    cin >> k >> n;


    priority_queue<long, vector<long>, greater<long>> res;
    //set<ll> res;
    int x;
    vector<int> prime(k);
    for (int i = 0; i < k; i++)
    {
        cin >> prime[i];
        res.push(prime[i]);
    }
    
    // x는 모두 소수
    // n번째만 구하면됨
    // 마지막 끝날때 수가 n번째 값이될것임
    long save = 0;
    int count = 0;
    while (count != n)
    {
       auto val = res.top();
       save = val;
        for (int i = 0; i < k; i++)
        {
           
            auto p = val * prime[i];
            res.push(p);
            
            if (val % prime[i]==0)
                break;

            
            
        }
         count++;
        res.pop();




    }
    cout << save << '\n';
    

}

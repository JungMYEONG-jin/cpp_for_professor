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

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.tie(NULL);
   
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> x(n); // 보석 무게 / 보석 가격
    vector<int> bag(k);
    
    for(int i=0;i<n;i++)
        cin>>x[i].first>>x[i].second; // 무게와 가격 입력
    
    for(int i=0;i<k;i++)
        cin>>bag[i];
    
    // 보석 무게별 가방 무게별 오름차순 정렬
    
    sort(bag.begin(), bag.end());
    sort(x.begin(), x.end());
    
    
    int idx=0;
    ll sum=0;
    priority_queue<int> res;
    
    // 보석 무게와 가방 무게를 비교하여 큐에 집어 넣는다.
    // 가방 하나마다 가방보다 equal or less 보석을 전부 비교하여 집어넣고
    // not empty면 최댓값 더해준후 pop 보석은 1개만 넣기 가능이므로
    // 현재 큐에 저장된 값들은 다음 가방 무게보다 무조건적으로 가벼우므로 이렇게하면 빨리 끝날것이라 생각
    
    for(int i=0;i<k;i++)
    {
        while(idx<n && x[idx].first<=bag[i])
        {
            res.push(x[idx].second);
            idx++;
        }
        
        if(!res.empty())
        {
            sum+=res.top();
            res.pop();
        }
    }
    
    
    cout<<sum<<'\n';
    return 0;
    
}

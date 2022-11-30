#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int n;
    cin>>n;
    
    vector<pair<int, int>> res(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>res[i].first>>res[i].second;
    }
    
    sort(res.begin(), res.end(), [](auto e, auto k){return e.first<k.first || e.first==k.first && e.second<k.second;});
    
    priority_queue<int, vector<int>, greater<int>> end_time;
    
    for(int i=0;i<n;i++)
    {
        if(!end_time.empty() && end_time.top()<=res[i].first )
            end_time.pop();
        end_time.push(res[i].second);
    }
    
    cout<<end_time.size()<<'\n';
    
    
    return 0;
}

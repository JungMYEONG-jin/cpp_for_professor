#include <string>
#include <vector>
#include <queue>

using namespace std;

int intensity[50001];
int node[50001];
vector<pair<int,int>> edge[50001];

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    fill(intensity, intensity+n+1, 1e8);
    for(auto summit : summits)
        node[summit] = 2; // 산봉우리

  for(auto& it : paths){
        edge[it[0]].push_back({it[2], it[1]}); // from cost to
        edge[it[1]].push_back({it[2], it[0]});
    }
  
    priority_queue<pair<int, int>> pq;
    for(auto gate : gates){
        intensity[gate] = -1; // 출입구
        pq.push({0, gate});
    }

    int ans = 1e9;
    int summit = 1e9;

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        if(it.first>ans)
            continue; //크면 볼필요없음

        if (node[it.second]==2) // 산봉우리
        {
            /* code */
            if (it.first<ans)
            {
                /* code */
                ans = it.first;
                summit = it.second; // 봉우리 교체
            }else if(it.first == ans && it.second<summit){
                summit = it.second;
            }
            continue;
        }
        
        for(auto next : edge[it.second]){
            if (intensity[next.second]>max(next.first, it.first))
            {
                /* code */
                intensity[next.second] = max(next.first, it.first);
                pq.push({intensity[next.second], next.second});
            }
            
        }
    }
    answer.push_back(summit);
    answer.push_back(ans);
    return answer;
}

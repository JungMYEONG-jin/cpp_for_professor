#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>

#define INF 999999999

using namespace std;

vector<pair<int, int>> graph[801];
int dist[801];

void getMinDist(int start){
    fill(dist, dist+801, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); // 0 start 1
    dist[start] = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int cur = it.second;
        int w = it.first;

        for(auto it2 : graph[cur]){
            int next = it2.first;
            int nextDist = it2.second;

            if(dist[next]>w+nextDist){
                dist[next] = w+nextDist;
                pq.push({w+nextDist, next});
            }
        }
    }

}





int main()
{
    
     int n, m;
     cin>>n>>m;

    

     int x, y, cost;
     for(int i=0;i<m;i++){
        cin>>x>>y>>cost;
        graph[x].push_back({y, cost});
        graph[y].push_back({x, cost});
     }


    int mx, my; //must x y
    cin>>mx>>my;
    
    int pathA, pathB;
    getMinDist(1);
    int a1 = dist[mx];
    getMinDist(mx);
    int a2 = dist[my];
    getMinDist(my);
    int a3 = dist[n];
    if(a1==INF || a2==INF || a3==INF)
    {
        pathA = INF;
    }else{
        pathA = a1+a2+a3;
    }

    getMinDist(1);
    int b1 = dist[my];
    getMinDist(my);
    int b2 = dist[mx];
    getMinDist(mx);
    int b3 = dist[n];

    if(b1==INF || b2==INF || b3==INF){
        pathB = INF;
    }else{
        pathB = b1+b2+b3;
    }

    if(pathA == INF && pathB == INF)
    {
        cout<<-1<<endl;
    }else{
        cout<<min(pathA, pathB)<<endl;
    }






 
    return 0;

}

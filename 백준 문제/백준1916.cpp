#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>

#define INF 999999999

using namespace std;

long long dist[1001];
int graph[1001][1001];

void dijkstra(int start, int bus) {
	
	fill(dist, dist + 1001, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();
		int cur = it.second;
		int w = it.first;
		
		
        for(int i=1;i<=bus;i++){
            int next = i;
            int nextW = graph[cur][i];
            
            if(nextW == INF)
                continue;
            long long res = nextW + w;
            if(dist[next]>res){
                dist[next] = res;
                pq.push({res, next});
            }
        }
        
        
        
	}


}



int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int x, y, cost;
    
    for(int i=1;i<=n;i++){
        fill(graph[i], graph[i]+1001, INF);
        graph[i][i] = 0;
    }
    
    
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> cost;
        if(graph[x][y]>cost)
		    graph[x][y] = cost;
	}
	int start, dest;
	cin >> start >> dest;
	dijkstra(start, n);

	cout << dist[dest];


	
	return 0;

}

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <limits>
#include <climits>

using namespace std;





int main()
{

int V, E;
cin>>V>>E; // input vertices count edge counts
int start;
cin>>start; // start position

vector<pair<int, int>> arr[V+1]; // vertices 만큼 

for(int i=0;i<E;i++)
{

int from, to, weight;
cin>>from>>to>>weight;
arr[from].push_back({to, weight});


}

int dist[V+1]; // array for min distance

fill(dist, dist+V+1, INT_MAX); // init inf else start postion

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
pq.push({0, start}); // start postion value 0

dist[start] = 0; // start position 0

while(!pq.empty())
{

int cost = pq.top().first;
int here = pq.top().second;

pq.pop();

for(auto i : arr[here])
{

int next = i.first;
int next_weight = i.second;

if(dist[next]>dist[here]+next_weight)
{
dist[next] = dist[here]+next_weight; // shortest path update
pq.push({dist[next], next});

}


}





}





for(int i=1;i<V;i++)
{
cout<<i<<" "<<dist[i]<<endl;

}





}




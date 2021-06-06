#include <iostream>
#include <climits>
#include <queue>

using namespace std;



#define inf INT_MAX

int main()
{

int V, E;
cin>>V>>E;
int start;
cin>>start;


vector<pair<int ,int>> arr[V+1];


for(int i=0;i<E;i++)
{

int from, to, weight;
cin>>from>>to>>weight;
arr[from].push_back({to, weight});

}


int dist[V+1];

fill(dist, dist+V+1, inf);

dist[start] = 0;


priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

pq.push({0, start});


while(!pq.empty())
{

int weight = pq.top().first;
int here = pq.top().second;
pq.pop();
for(auto i : arr[here])
{
int next = i.first;
int next_weight = i.second;

if(dist[next]>dist[here]+next_weight)
{
dist[next] = dist[here]+next_weight;
pq.push({dist[next], next});

}

}



}


for(int i=1;i<=V;i++)
{

if(dist[i]!=inf)
	cout<<dist[i]<<'\n';
else
	cout<<"INF\n";

}









}

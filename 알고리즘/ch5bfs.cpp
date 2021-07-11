#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <queue>
#include <stack>

using namespace std;

class Graph
{
int V;
list<int>* adj;
public:

Graph(int V)
{
this->V = V;
adj = new list<int>[V];
}


void addEdge(int v, int w)
{
adj[v].push_back(w);
}

void bfs(int s)
{

vector<bool> visited(V,false);

queue<int> que;
visited[s] = true;
que.push(s);


while(!que.empty())
{
s = que.front();
//cout<<s<<" ";
que.pop();


for(auto i : adj[s])
{
if(!visited[i])
{
visited[i] = true;
cout<<s<<" "<<i<<endl;
que.push(i);

}

}



}


}


void dfs(int s)
{

vector<bool> visited(V, false);
stack<int> st;
st.push(s);


while(!st.empty())
{

s = st.top();
st.pop();

if(!visited[s])
{

cout<<s<<" ";
visited[s]=true;

}


for(auto i : adj[s])
{
if(!visited[i])
{
st.push(i);
}


}



}


}








};





int main()
{

int V, start;
cin>>V>>start;

Graph g(V);
int from, to;
while(true)
{
cin>>from>>to;
if(from==-1 && to==-1)
	break;

g.addEdge(from, to);



}

g.bfs(start);








}

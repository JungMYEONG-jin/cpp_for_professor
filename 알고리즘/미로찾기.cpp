#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>



using namespace std;

const int inf = 0x3f3f3f3f;

struct Edge
{
    int to, cost;
    Edge(int _to = 0, int _cost = 0) : to(_to), cost(_cost) {}
    
};

struct Node
{
    vector<Edge> straight;
    vector<Edge> rev;
};

vector<Node> res;
vector<bool> isTrap;


void push(priority_queue<tuple<int, int, map<int, int>>>& q, map<pair<int, map<int, int>>,bool>& db , int dist, int now, map<int, int> state, int next, int cost)
{
    if(isTrap[next])
        state[next] = (++state[next])%2;
    if(!db[{next, state}])
        q.push({dist-cost, next, state});
     
}


int dijkstra(int start, int end)
{
    
    map<pair<int, map<int, int>>, bool> db;
    priority_queue<tuple<int, int, map<int, int>>> q;
    q.push({0, start, map<int, int>()});
    
    while(!q.empty())
    {
        auto[dist, cur, state] = q.top();
        q.pop();
        if(cur==end)
            return -dist;
        auto& check = db[{cur, state}];
        if(check)
            continue;
        else
            check = true;
        
        for(auto& e : res[cur].straight)
        {
            int next = e.to;
            int cost = e.cost;
            if((state[cur]+state[next])%2==0)
            {
                push(q, db, dist, cur, state, next, cost);
            }
            
        }
        
        for(auto& e : res[cur].rev)
        {
            int next = e.to;
            int cost = e.cost;
            if((state[cur]+state[next])==1)
            {
                push(q, db, dist, cur, state, next, cost);
            }
        }
        
        
    }
    
    return inf;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    
    res.resize(n+1);
    isTrap.resize(n+1);
    for(auto& road : roads)
    {
        int s = road[0];
        int to = road[1];
        int dist = road[2];
        res[s].straight.push_back(Edge(to, dist));
        res[to].rev.push_back(Edge(s, dist));
    }
    
    for(auto i : traps)
    {
        isTrap[i] = true;
    }
    
    answer = dijkstra(start, end);
    
    return answer;
}

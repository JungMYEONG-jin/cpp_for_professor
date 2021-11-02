#include <iostream>
#include <queue>

using namespace std;

int dist[100001];
bool visited[100001];

int main()
{
    queue<pair<int, int>> q;
    int A, B, N, M;
    cin>>A>>B>>N>>M;
    int power[8] = {1,-1,A,B,-A,-B,A,B};    
	int result = 0;
	q.push({N,0});
	visited[N] = true;
	while(!q.empty())
	{
	    int x = q.front().first;
	    int dist = q.front().second;
	    q.pop();
	    if(x==M) // 주미를 만나면 break
	    {
	        result = dist;
	        break;
	    }
	    for(int i=0;i<8;i++)
	    {
	        int nx = x;
	        if(i>=6)
	        {
	            nx*=power[i];
	        }else
	            nx+=power[i];
	        if(nx>=0 && nx<100001 && !visited[nx])
	        {
	            visited[nx] = true;
	            q.push({nx, dist+1});
	        }
	    }
	}
	cout<<result<<endl;
	
}

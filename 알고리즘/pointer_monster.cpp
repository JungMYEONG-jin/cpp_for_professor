#include <cstdio>
#include <queue>
#include <cmath>
#include <string>
using namespace std;


int Ver;
const int Total = 50000;
int go[4][2] = {
	0,1,1,0,0,-1,-1,0
};

struct Node {
	int next, cur;
	bool operator<(const Node& n) const {
		return cur > n.cur;
	}
};


int Dijkstra(vector<Node> edge[Total], int src)
{
	vector<int> dist(Ver, -1);
	priority_queue<Node> PQ;
	dist[src] = 0;
	Node temp;
	temp.next = src;
	temp.cur = dist[src];
	PQ.push(temp);

	while (!PQ.empty()) {
		temp = PQ.top();
		PQ.pop();
		int u = temp.next;
		if (u == Ver - 1)
			return dist[u];
		for (int i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i].next;
			int c = edge[u][i].cur;
			if (dist[v] == -1 || dist[u] + c < dist[v]) {
				dist[v] = dist[u] + c;
				temp.cur = dist[v], temp.next = v;
				PQ.push(temp);
			}
		}
	}

	return dist[Ver - 1];
}

int path_finder(string maze)
{
	int len = floor(sqrt((double)maze.size()));
	
	Ver = len * len;
	vector<Node> edge[Total];
	for (int i = 0; i < Ver; i++)
		edge[i].clear();
	for (int i = 0; i < len; i++)
	{
		for (int y = 0; y < len; y++)
		{
			for (int j = 0; j < 4; j++)
			{
				int ni = i + go[j][0];
				int ny = y + go[j][1];
				if (ni < 0 || ni >= len || ny < 0 || ny >= len)
					continue;
				Node temp;
				temp.next = ni * len + ny;
				temp.cur = abs(maze[ni * (len + 1) + ny] - maze[i * (len + 1) + y]);
				edge[i * len + y].push_back(temp);
			}
		}
	}
	int src = 0;
	return Dijkstra(edge, src);
}

























char a[4][7] = { "Common", "Point", "Boost", "Better" };

char(*b[4])[7] = { a + 3, a + 1, a, a + 2 };

char(*(*c())[4])[7]
{
	return &b;
}

char(**d())[7]
{
	return c()[1] - 3;
}

char buf[256];

char* pointer_monster(char(**(*f)())[7])
{
	int len;

	len = sprintf(buf, "%s", *f()[0]);
	len += sprintf(buf + len, "%s ", *((**f)() - 1)[0] + 4);
	len += sprintf(buf + len, "%s", (*f())[1] - 4);
	len += sprintf(buf + len, "%s", f()[0][2] + 3);
	len += sprintf(buf + len, "%s", *((**f)() - 1)[0] + 4);
	return buf;
}



//Best code
/*
auto C(void)
{
  return &b;
}

char(**d())[7]
{
  return C()[1] - 3;
}

char buf[256];

char* pointer_monster(char(**f(void))[7])
{
  int len;

  len = sprintf(buf, "%s", *f()[0]);
  len += sprintf(buf + len, "%s ", *((**f)() - 1)[0] + 4);
  len += sprintf(buf + len, "%s", (*f())[0] - 4);
  len += sprintf(buf + len, "%s", f()[1][2] + 3);
  len += sprintf(buf + len, "%s", *((**f)() - 1)[0] + 4);
  return buf;
}



*/

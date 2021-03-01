#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <regex>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <sstream>

using namespace std;

typedef long long ll;

int root[10001];

int find(int x)
{
    if (root[x] == x)
        return x;
    return root[x]= find(root[x]);
}

void unions(int x, int y)
{
    x = find(x);
    y = find(y);
    root[y] = x;
}

bool Same_Root(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return true;
    return false;
}


bool visited[101];
int computer[101][101];
int number = 0;

void DFS(int start, int end)
{
    visited[start] = true;
    number++;
    for (int i = 1; i <= end; i++)
    {
        if (computer[start][i] == 1 && !visited[i])
        {
            DFS(i, end);
        }
    }
}




int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.tie(NULL);
    
    int g, p;
    cin >> g >> p;
    int a, b;
    for (int i = 0; i < p; i++)
    {
        cin >> a >> b;
        computer[a][b] = 1;
        computer[b][a] = 1;
    }

    DFS(1, g);


    cout << number-1;

    return 0;
}

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


string graph[10000];
bool visited[10000][500];

int R, C;

typedef struct
{
    int x, y;
}Direction;

Direction dir[3] = { {-1, 1}, {0, 1}, {1,1} };

bool DFS(int x, int y)
{
    visited[x][y] = true;
    if (y == C - 1)
        return true;

    for (int i = 0; i < 3; i++)
    {
        // 오른쪽 위 오른쪽 오른쪽아래
        int nextX = x + dir[i].x;
        int nextY = y + dir[i].y;

        if (0 <= nextX && nextX < R && 0 <= nextY && nextY < C)
        {
            if (!visited[nextX][nextY] && graph[nextX][nextY] == '.')
            {
                bool flag = DFS(nextX, nextY);
                if (flag)
                    return flag;
            }
        }
    }
    return false;
}











int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.tie(NULL);
    
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> graph[i];

    int count = 0;

    for (int i = 0; i < R; i++)
        count += DFS(i, 0);

    cout << count;

    return 0;
}

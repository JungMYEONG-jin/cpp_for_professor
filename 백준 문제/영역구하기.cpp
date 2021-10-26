#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <set>
#include <list>
#include <cstring>


using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };





int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
 
    
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> db(m, vector<int>(n, 1));
    bool visited[100][100];
    // 사각형 0으로
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = y1; x <= y2 - 1; x++)
        {
            for (int y = x1; y <= x2 - 1; y++)
            {
                db[x][y] = 0;
            }


        }
    }



    

    vector<int> res;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && db[i][j] == 1)
            {
                queue<pair<int, int>> q;
                q.push({ i,j });
                visited[i][j] = true;
                int cnt = 0;
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    cnt++;
                    for (int d = 0; d < 4; d++)
                    {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx >= 0 && ny >= 0 && nx < m && ny < n)
                        {
                            if (!visited[nx][ny] && db[nx][ny] == 1)
                            {
                                visited[nx][ny] = true;
                                q.push({ nx, ny });
                            }
                        }
                    }



                }
                res.push_back(cnt);
            }
        }
    }
    sort(res.begin(), res.end());
    cout<<res.size()<<'\n';
    for (auto i : res)
        cout << i <<" ";
}

#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int r, c;
char db[250][250];
bool visited[250][250];

int sheep = 0;
int wolf = 0;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0,0,1,-1 };
int main()
{
   
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < c; j++)
            db[i][j] = str[j];
    }

    //memset(visited, false, sizeof(visited));
    // . 빈칸 이동 가능 
    // # 울타리
    // 양
    // 늑대

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!visited[i][j] && db[i][j] != '#')
            {
                visited[i][j] = true;
                vector<char> res;
                queue<pair<int, int>> q;
                q.push({ i,j });
                //cout << i << " " << j << endl;
                res.push_back(db[i][j]);
                while (!q.empty())
                {
                    int x, y;
                    x = q.front().first;
                    y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < r && ny < c)
                        {
                            if (!visited[nx][ny] && db[nx][ny] != '#')
                            {
                                visited[nx][ny] = true;
                                res.push_back(db[nx][ny]);
                                q.push({ nx, ny });
                            }
                        }
                    }
                }
                int n1 = count(res.begin(), res.end(), 'v');
                int n2 = count(res.begin(), res.end(), 'o');
               //cout << n1 << " " << n2 << endl;
                if (n1 >= n2)
                    wolf += n1;
                else
                    sheep += n2;
            }
        }
    }

    cout << sheep << " " << wolf;


}

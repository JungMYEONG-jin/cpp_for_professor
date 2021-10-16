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

#define INF 999999999

using namespace std;

vector<vector<int>> db;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };


int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> res;
    string temp_;
    for (int i = 0; i < n; i++)
    {
        cin >> temp_;
        res.push_back(temp_);
    }
    db.resize(n, vector<int>(n));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < n; j++)
        {
            db[i][j] = res[i][j] - '0';
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && db[i][j]==1)
            {
                queue<pair<int, int>> q;
                q.push({ i,j });
                visited[i][j] = true;
                //set<pair<int,int>> sdb;
                int cnt = 0;
                
                while (!q.empty())
                {
                    auto it = q.front();
                    int x = it.first;
                    int y = it.second;
                    //sdb.insert({ x,y });
                    cnt++;
                    q.pop();
                    //cout << x << " " << y << endl;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                        {
                            if (visited[nx][ny] == false && db[nx][ny] == 1)
                            {
                                visited[nx][ny] = true;
                                db[nx][ny] = 0;
                                q.push({ nx, ny });
                            }
                        }
                    }
                }
                result.push_back(cnt);
            }
        }
    }

    int len = result.size();
    sort(result.begin(), result.end());
    cout << len << endl;
    for (auto i : result)
        cout << i << endl;



	
}

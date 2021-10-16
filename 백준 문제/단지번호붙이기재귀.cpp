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
bool visited[25][25];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int cnt;
int n;
void dfs(int x, int y)
{
    visited[x][y] = true;
    cnt++;
    for(int i=0;i<4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0 && nx<n &&ny>=0 && ny<n)
        {
            if(visited[nx][ny]==false && db[nx][ny]==1)
                dfs(nx, ny);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

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
    
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && db[i][j]==1)
            {
                cnt=0;
                dfs(i,j);
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

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

#define INF 999999999

using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
char db[100][100];
bool visited[100][100];
bool visited2[100][100];
int n;

void valid(int i, int j, char ch, vector<int>& result)
{
    if (!visited[i][j] && db[i][j] == ch)
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
                if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                {
                    if (!visited[nx][ny] && db[nx][ny] == ch)
                    {
                        visited[nx][ny] = true;
                        q.push({ nx,ny });
                    }
                }
            }
        }
        result.push_back(cnt);
        //cout << cnt << endl;

    }
    return;

}

void valid2(int i, int j, char ch,char ch2, vector<int>& result)
{
    if (!visited2[i][j] && (db[i][j] == ch || db[i][j] == ch2))
    {
        queue<pair<int, int>> q;
        q.push({ i,j });
        visited2[i][j] = true;
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
                if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                {
                    if (!visited2[nx][ny] && (db[nx][ny] == ch || db[nx][ny]==ch2))
                    {
                        visited2[nx][ny] = true;
                        q.push({ nx,ny });
                    }
                }
            }
        }
        result.push_back(cnt);
    }
    return;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
 
    
    cin >> n;
    vector<string> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }

    memset(visited, false, sizeof(visited));
    memset(visited2, false, sizeof(visited2));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            db[i][j] = res[i][j];
        }
    }



    vector<int> result;
    vector<int> result2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
          
            valid(i, j, 'R', result);
            valid(i, j, 'G', result);
            valid(i, j, 'B', result);
            valid2(i, j, 'R', 'G', result2);
            valid2(i, j, 'B', 'B', result2);
        }
    }

    cout << result.size() << " " << result2.size() << endl;
    //cout << result2.size() << endl;


	
}

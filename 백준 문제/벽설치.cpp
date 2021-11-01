#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <cstring>

using namespace std;

int r, c;
char db[500][500];


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

    bool flag = false;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (db[i][j] == 'S')
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && ny >= 0 && nx < r && ny < c)
                    {
                        if (db[nx][ny] == 'W') // 늑대라면 실패
                        {
                            flag = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    if (flag)
    {
        cout << 0 << endl;
        return 0;
    }
    // 양옆에 늑대가 없다면
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (db[i][j] == 'S')
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && ny >= 0 && nx < r && ny < c)
                    {
                        if (db[nx][ny] == '.') // 상하좌우에 벽을설치해주자
                        {
                            db[nx][ny] = 'D';
                        }
                    }
                }
            }
        }
    }
    cout << 1 << '\n';
    for (int i = 0; i < r; i++)
    {
       
        for (int j = 0; j < c; j++)
            cout << db[i][j];
        cout << '\n';
    }

}

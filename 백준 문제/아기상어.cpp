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

int n, m;

int db[20][20];
bool visited[20][20];
vector<tuple<int, int, int>> fish; // x y time
tuple<int, int, int, int, int> shark; // x y eat time size
void bfs(int sx, int sy)
{
    queue<tuple<int, int, int>> q; // x, y,time
    q.push({ sx,sy,0 }); // x, y ,time
    visited[sx][sy] = true;
    while (!q.empty())
    {
        int x, y, time;
        tie(x, y,time) = q.front();
        q.pop();
      
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n)
            {
                if (!visited[nx][ny])
                {
                    if (db[nx][ny] == 0)
                    {
                        visited[nx][ny] = true;
                        q.push({ nx, ny,time + 1 });
                    }
                    else if (db[nx][ny] < get<4>(shark))
                    {
                        visited[nx][ny] = true;
                        fish.push_back({ nx,ny,time + 1 });
                        q.push({ nx, ny, time + 1 });
                    }
                    else if (db[nx][ny] == get<4>(shark))
                    {
                        visited[nx][ny] = true;
                        q.push({ nx, ny, time + 1});
                    }
               }
            
            }
                
          }
      }
    


}


int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n;
    int sx, sy;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> db[i][j];
            if (db[i][j] == 9)
            {
                sx = i;
                sy = j;
                shark = { sx, sy, 0, 0, 2 };
            }

        }
    }


    while (true)
    {
        fish.clear();
        memset(visited, false, sizeof(visited));
        bfs(get<0>(shark), get<1>(shark));
        if (fish.size() == 0)
        {
            cout << get<3>(shark) << endl;
            break;
        }
        else if (fish.size() == 1)
        {
            auto it = fish[0];
            db[get<0>(it)][get<1>(it)] = 9;
            db[get<0>(shark)][get<1>(shark)] = 0;
            get<0>(shark) = get<0>(it);
            get<1>(shark) = get<1>(it);
            get<2>(shark) = get<2>(shark)+1; // eat count
            get<3>(shark) = get<3>(shark) + get<2>(it); // time plus

            if (get<4>(shark) == get<2>(shark))
            {
                get<4>(shark) = get<4>(shark) + 1;
                get<2>(shark) = 0;
            }
        }
        else
        {
            sort(fish.begin(), fish.end(), [](auto e, auto k) {
                if (get<2>(e) <= get<2>(k))
                {
                    if (get<2>(e) == get<2>(k))
                    {
                        if (get<0>(e) <= get<0>(k))
                        {
                            if (get<0>(e) == get<0>(k))
                            {
                                if (get<1>(e) < get<1>(k))
                                {
                                    return true;
                                }
                                return false;
                            }
                            return true;
                        }
                        return false;
                    }return true;
                }
                return false;
                });

                auto it = fish[0];
                db[get<0>(it)][get<1>(it)] = 9;
                db[get<0>(shark)][get<1>(shark)] = 0;
                get<0>(shark) = get<0>(it);
                get<1>(shark) = get<1>(it);
                get<2>(shark) = get<2>(shark)+1; // eat count
                get<3>(shark) = get<3>(shark) + get<2>(it); // time plus

                if (get<4>(shark) == get<2>(shark))
                {
                    get<4>(shark) = get<4>(shark) + 1;
                    get<2>(shark) = 0;
                }




        }
    }

    
}

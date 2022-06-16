#include <iostream>
#include <queue>


using namespace std;

int n, m;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int graph[50][50];
bool visited[50][50];

bool check(int x, int y)
{
    if(x>=0 && y>=0 && x<n && y<m)
        return true;
    return false;
}

void dfs(int x, int y, int dir, int sum){

    for(int i=0;i<4;i++)
    {
        int ndir = (dir+3-i) % 4;
        int nx = x+dx[ndir];
        int ny = y+dy[ndir];
        if(!check(nx, ny) || graph[nx][ny]==1)
            continue;

        if(!visited[nx][ny] && graph[nx][ny]==0){
            visited[nx][ny] = true;
            dfs(nx, ny, ndir, sum+1); //1번으로 back
        }
    }

    int back = dir+2 < 4 ? dir+2 : dir-2;
    int backX = x+dx[back];
    int backY = y+dy[back];
    if(0<=backX && backX<n && backY>=0 && backY<m){
        if(graph[backX][backY]==0){
            dfs(backX, backY, dir, sum);
        }
        else{
        cout<<sum<<endl;
        exit(0);
    }
    }


}


int main()
{
   
    cin>>n>>m;

    int rx, ry, direction;
    cin>>rx>>ry>>direction;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>graph[i][j];
            visited[i][j] = false;
        }
    }

    visited[rx][ry] = true;

    dfs(rx, ry, direction, 1);

    return 0;



}

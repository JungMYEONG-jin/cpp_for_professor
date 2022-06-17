#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int maxVal = -INT_MAX;
int minVal = INT_MAX;
int n;
char graph[6][6];
int dx[2] = {1,0};
int dy[2] = {0,1};

bool check(int x, int y){
    if(x>=0 && y>=0 && x<n & y<n)
        return true;
    return false;
}

void dfs(int x, int y, int prev, char ch){
    for(int i=0;i<2;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(check(nx, ny)){
            if(graph[nx][ny]=='+'){
                dfs(nx, ny, prev, '+');
            }else if(graph[nx][ny]=='-'){
                dfs(nx, ny, prev, '-');
            }else if(graph[nx][ny]=='*'){
                dfs(nx, ny, prev, '*');
            }else{
                int temp;
                if(ch=='+'){
                    temp = prev + (graph[nx][ny]-'0');
                }else if(ch=='-'){
                    temp = prev - (graph[nx][ny]-'0');
                }else if(ch=='*'){
                    temp = prev * (graph[nx][ny]-'0');
                }

                if(nx==n-1 && ny==n-1){
                    maxVal = max(maxVal, temp);
                    minVal = min(minVal, temp);
                    return ;
                }

                dfs(nx, ny, temp, graph[nx][ny]);
            }
        }



    }
}



int main()
{
   cin>>n;

    string str;
   for(int i=0;i<n;i++)
   {
     for(int j=0;j<n;j++)
     {
        cin>>graph[i][j];
     }
   }

    dfs(0, 0, graph[0][0]-'0', graph[0][0]);

    cout<<maxVal<<" "<<minVal<<endl;

}

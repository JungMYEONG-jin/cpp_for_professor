#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>


using namespace std;


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

char db[50][50];
bool visited[50][50];
int n, m;

int main()
{
    
   string str;
   cin>>n>>m;
   for(int i=0;i<n;i++)
   {
       cin>>str;
       for(int j=0;j<m;j++)
       {
           db[i][j] = str[j];
       }
   }
   
   vector<int> res;
   
    for(int i=0;i<n;i++)
    {
       
       for(int j=0;j<m;j++)
       {
           if(!visited[i][j] && db[i][j]=='L')
           {
               queue<tuple<int, int, int>> q;
               q.push({i, j, 0});
               visited[i][j] = true;
               int maxlen = 0;
               while(!q.empty())
               {
                   auto it = q.front();
                   int x,y,dist;
                   tie(x,y,dist) = it;
                   q.pop();
                   if(maxlen<dist) maxlen = dist;
                
                   for(int k=0;k<4;k++)
                   {
                       int nx = x+dx[k];
                       int ny = y+dy[k];
                       if(nx>=0 && ny>=0 && nx<n && ny<m)
                       {
                           if(!visited[nx][ny] && db[nx][ny]=='L')
                           {
                               q.push({nx, ny, dist+1});
                               visited[nx][ny] = true;
                           }

                           
                       }
                   }
                   
               }
               res.push_back(maxlen);
               memset(visited, false, sizeof(visited));
        
           }
       }
    }
   
   
   sort(res.begin(), res.end());
   cout<<res.back()<<endl;
   
   
   
}

#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>

#define INF 999999999

using namespace std;


int dx[4] = { 1,-1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    int dist[126][126];
    int arr[126][126];
    int idx=1;
    while(true){
        cin>>n;
        
        if(n==0)
            break;
        
        for(int i=0;i<n;i++){
            fill(dist[i], dist[i]+126, INF);
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        dist[0][0] = arr[0][0]; // 첫 시작 손실
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int x = it.first;
            int y = it.second;
            
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(nx>=0 && ny>=0 && nx<n && ny<n){
                    if(dist[nx][ny] > dist[x][y] + arr[nx][ny]){
                        dist[nx][ny] = dist[x][y] + arr[nx][ny];
                        pq.push({nx, ny});
                    }
                }
            }
        }
        cout << "Problem " <<idx++<<": "<<dist[n-1][n-1]<< '\n';

    }
    return 0;
}

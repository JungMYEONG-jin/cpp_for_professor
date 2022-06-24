> 숫자 고르기

- 문제를 그림으로 그리다보면 결국 1, 3, 5 는 자신에서 출발해 자신으로 돌아오는 circle형태임.
- circle 애들 정렬해서 return하면됨.



```c++
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

int graph[101];
bool visited[101];
int arr[101];
int n, cnt = 0;


void dfs(int cur, int target){
    if(visited[cur]){
        if(cur==target){
            arr[cnt++] = target;
        }
    }else{
        visited[cur] = true;
        dfs(graph[cur], target);
    }
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> graph[i];
	}

	for (int i = 1; i <= n; i++) {
		fill(visited, visited + 101, false);
		dfs(i, i);
	}

	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		cout << arr[i] << '\n';
	}
	

	return 0;

}
```

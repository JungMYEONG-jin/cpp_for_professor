#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <set>
#include <numeric>
#include <cmath>
#include <stack>

#define INF 1000000000

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


int bfs(int storey) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({ 0, storey });
    while (!q.empty()) {
        int cur = q.top().second;
        int cnt = q.top().first;
        q.pop();

        if (cur == 0) {
            return cnt;
        }
        int a = cur % 10;
        int next = cur / 10;
        q.push({ cnt + a, next });
        q.push({ cnt + 10 - a, next + 1 });
    }
}

int solution(int storey) {
    int ans = bfs(storey);
    return ans;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << solution(678) << endl;
    cout << solution(5) << endl;
    cout << solution(15) << endl;
    cout << solution(95) << endl;
    cout << solution(999) << endl;
    cout << solution(2554) << endl;

    
   
}
// 2335

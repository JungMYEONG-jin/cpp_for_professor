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

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    // 무적권을 소모해서 막던지
    // 병사를 소모해서 막던지
    int len = enemy.size();
    if (k >= len)
        return len;
    priority_queue<int> q;
  

    for (int i = 0; i < len; i++) {
        if (n >= enemy[i]) {
            n -= enemy[i];
            q.push(enemy[i]);
            answer++;
        }
        else {
            if (k > 0) {
                k--;
                if (!q.empty()) {
                    int cur = q.top();
                    if (cur > enemy[i]) {
                        q.pop();
                        n += cur;
                        i--;
                    }
                    else
                        answer++;
                }
                else
                    answer++;
            }
            else
                break;
        }
        
    }

    return answer;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << solution(7, 3, { 4,2,4,5,3,3,1 }) << endl;
    cout << solution(2, 4, { 3, 3, 3, 3 }) << endl;
}
// 2335

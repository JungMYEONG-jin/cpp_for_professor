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

int solution(vector<int> cards) {
    int answer = 0;
    
    
    for (auto card : cards) {
        bool visited[101] = { false, };
        int idx = card;
        int left = 0;
        while (true) {
            if (visited[idx -1])
                break;
            visited[idx -1] = true;
            left++;
            idx = cards[idx - 1];
        }
        vector<int> temp;
        for (int i = 0, len = cards.size(); i < len; i++) {
            if (!visited[i])
                temp.push_back(cards[i]);
        }
        int right = 0;
        for (auto card : temp) {
            int idx2 = card;
            int other = 0;
            while (true) {
                if (visited[idx2-1])
                {
                    right = max(right, other);
                    break;
                }
                visited[idx2 - 1] = true;
                other++;
                idx2 = cards[idx2 - 1];
            }
        }
        answer = max(answer, left * right);
    }
  
    return answer;
}

int dp[100001];
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    pair<int, int> arr[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    

    for (int i = 1; i <= N; i++) {
        for (int j = K; j >= 1;j--) {
            if(j>=arr[i].first)
                dp[j] = max(dp[j], dp[j - arr[i].first]+arr[i].second);
        }
    }


    return 0;

}

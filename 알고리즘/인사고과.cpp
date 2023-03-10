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

int solution(vector<vector<int>> scores) {
    int answer = 0;
    vector<int> temp = scores[0];
    int left = scores[0][0];
    int right = scores[0][1];
    int my = left + right;

    stable_sort(scores.begin(), scores.end(), [](auto it, auto it2) {
        return it[0] > it2[0] || (it[0] == it2[0] && it[1] < it2[1]);
        });


    int prev = scores[0][1];
    for (auto& score : scores) {
        if (prev > score[1]) {
            if (left == score[0] && right == score[1])
                return -1;
            score[0] = -1;
            score[1] = -1;
        }
        else {
            prev = score[1];
        }

    }

    stable_sort(scores.begin(), scores.end(), [](auto it, auto it2) {
        return (it[0] + it[1]) > (it2[0] + it2[1]);
        });


    return find(scores.begin(), scores.end(), temp) - scores.begin() + 1;
}


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> maps = { "SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE" };
    vector<string> maps2 = { "LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO" };
    vector<string> maps3 = { "SOOOO", "XXXXX", "LOOOO", "XXXXX", "EOOOO" };
    vector<string> maps4 = { "SOOOL", "OXXXO", "OOOOO", "OXXXX", "EOOOO" };
    cout << solution(maps) << endl;
    cout << solution(maps2) << endl;
    cout << solution(maps3) << endl;
    cout << solution(maps4) << endl;

    vector<vector<int>> scores = { {2, 2}, {1, 4}, {3, 2}, {3, 2}, {2, 1} };
    solution(scores);

}
// 2335

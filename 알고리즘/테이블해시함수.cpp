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

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    sort(data.begin(), data.end(), [col](auto it, auto it2) {
        return it[col-1] < it2[col-1] || (it[col-1] == it2[col-1] && it[0] > it2[0]);
        });

    for (int i = row_begin - 1; i < row_end; i++) {
        transform(data[i].begin(), data[i].end(), data[i].begin(), [i](int num) {return num % (i+1); });
        int cur = accumulate(data[i].begin(), data[i].end(), 0);
        answer ^= cur;
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

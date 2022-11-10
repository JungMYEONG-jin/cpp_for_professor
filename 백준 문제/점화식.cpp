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



int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n;
	cin >> n;
	long long t[36] = { 0, };

	t[0] = 1;
	t[1] = 1;
	t[2] = 2;
	t[3] = 5;
	// 03 12 21 30
	for (int i = 4; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			t[i] += (t[i - j] * t[j - 1]);
		}
	}

	cout << t[n] << endl;


    return 0;

}

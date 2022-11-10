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
    
	int A[46];
	int B[46];
	A[1] = 0;
	B[1] = 1;
	A[2] = 1;
	B[2] = 1;
	A[3] = 1;
	B[3] = 2;
	A[4] = 2;
	B[4] = 3;
	B[5] = 5;
	A[5] = 3;
	int n;
	cin >> n;
	for (int i = 4; i <= n; i++) {
		B[i] = B[i - 1] + B[i - 2];
		A[i] = A[i - 1] + A[i - 2];
	}

	cout << A[n] << " " << B[n] << endl;

    return 0;

}

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
    

	int day, food;
	cin >> day >> food;

	int A[31];
	int B[31];

	A[0] = 0;
	A[1] = 1;
	A[2] = 0;
	B[0] = 0;
	B[1] = 0;
	B[2] = 1;

	for (int i = 3; i <= day; i++) {
		A[i] = A[i - 1] + A[i - 2];
		B[i] = B[i - 1] + B[i - 2];
	}

	int a, b;
	for (int i = 1; i <= food / A[day]; i++) {
		int k = food - i * A[day];
		if (k % B[day] == 0) {
			a = i;
			b = k / B[day];
			break;
		}
	}
	cout << a << "\n" << b << endl;


    return 0;

}

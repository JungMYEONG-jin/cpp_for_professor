#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>

#define INF (long long)1e15

using namespace std;

int n, ans;
int maxVal = 0;
int minVal = 1000000000;
int minAns, maxAns;
int stats[21][21];
bool checked[21];

vector<string> vec;

bool visited[11];
char op[11];


bool isValid(char i, char j, char ops) {
	if (ops == '>')
		return i > j;
	else if (ops == '<')
		return i < j;
	return true;
}


void getMinMaxNum(int x, string str) {
	if (x == n + 1) {
		vec.push_back(str);
		return;
	}

	for (int i = 0; i <10; i++) {
		if (visited[i])
			continue;
		if (x == 0 || isValid(str[x-1], i+'0', op[x-1]))
		{
			visited[i] = true;
			getMinMaxNum(x + 1, str+to_string(i));
			visited[i] = false;
		}
	}
}






void dfs(int x, int pos) {


	if (x == n / 2) {
		
		int start = 0, link = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (checked[i] && checked[j])
					start += stats[i][j];
				else if (!checked[i] && !checked[j])
					link += stats[i][j];
			}
		}

		int val = abs(start - link);
		ans = min(ans, val);
		return;
	}

	for (int i = pos; i < n; i++)
	{
		checked[i] = true;
		dfs(x + 1, i + 1);
		checked[i] = false;
	}

}



int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> op[i];
	}
	
	getMinMaxNum(0, "");
	sort(vec.begin(), vec.end());
	cout << vec.back() << endl;
	cout << vec.front() << endl;

	return 0;

}

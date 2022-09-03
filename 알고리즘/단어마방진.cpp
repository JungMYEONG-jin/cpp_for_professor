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

vector<string> arr;
vector<string> temp(20, "");
bool visited[21];
int col, row;

void dfs(int idx) {
	

	if (idx == col) {
		bool flag = true;
		for (int i = 0; i < col; i++) {
			for (int j = i + 1; j < col; j++) {
				flag &= (temp[i][j] == temp[j][i]);
			}
		}
		if (flag) {
			for (int i = 0; i < col; i++) {
				for (int j = 0; j < col; j++) {
					cout << temp[i][j];
				}
				cout << '\n';
			}
			exit(0);
		}
		return;
	}

	for (int i = 0; i < row; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		temp[idx] = arr[i];
		dfs(idx + 1);
		visited[i] = false;
	}

}


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> col >> row;
	string str;
	for (int i = 0; i < row; i++) {
		cin >> str;
		arr.push_back(str);
	}

	sort(arr.begin(), arr.end());
	dfs(0);

	cout << "NONE";
	

	return 0;

}

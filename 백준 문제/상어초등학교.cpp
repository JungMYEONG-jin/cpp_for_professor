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

#define INF (long long)1e15

using namespace std;

struct student {
	int from;
	int like[4];
};

struct pos {
	int x, y, empty, likeFriend;
};

int n;
vector<student> arr;
student studentArr[401];
int graph[21][21];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0 , 1, -1 };


bool getOrder(pos a, pos b) {

	if (a.likeFriend >= b.likeFriend) {
		if (a.likeFriend == b.likeFriend) {
			if (a.empty >= b.empty) {
				if (a.empty == b.empty) {
					if (a.x <= b.x) {
						if (a.x == b.x) {
							if (a.y < b.y) {
								return true;
							}
							return false;
						}
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	int num = n * n;
	int from, a, b, c, d;
	for (int i = 0; i < num; i++) {
		cin >> from >> a >> b >> c >> d;
		arr.push_back({ from, {a, b, c, d} });
		studentArr[from].from = from;
		studentArr[from].like[0] = a;
		studentArr[from].like[1] = b;
		studentArr[from].like[2] = c;
		studentArr[from].like[3] = d;
	}

	for (int i = 0, len = arr.size(); i < len; i++) {
		vector<pos> temp;
		int from = arr[i].from;
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (graph[x][y] != 0)
					continue;
				int curEmpty = 0;
				int curFriend = 0;
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx<0 || ny<0 || nx>=n || ny>=n)
						continue;
					if (graph[nx][ny] == 0)
						curEmpty++;
					else {
						for (int j = 0; j < 4; j++) {
							int curFriendNum = arr[i].like[j];
							if (graph[nx][ny] == curFriendNum) {
								curFriend++;
								break;
							}
						}
					}
				}
				temp.push_back({ x, y, curEmpty, curFriend });
			}

		}
		sort(temp.begin(), temp.end(), getOrder);
		graph[temp[0].x][temp[0].y] = from; // 해당 조건 정렬후 첫 자리에 배치
		
	}

	auto getScore = [](int f) {
		if (f == 0)
			return 0;
		return static_cast<int>(pow(10, f - 1));
	};

	int score = 0;
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++) {
			int from = graph[x][y];
			int Friend = 0;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					continue;
				for (int i = 0; i < 4; i++) {
					int like = studentArr[from].like[i];
					if (like == graph[nx][ny])
					{
						Friend++;
						break;
					}
				}

			}
			score += getScore(Friend);
		}
	}

	cout << score << endl;

}

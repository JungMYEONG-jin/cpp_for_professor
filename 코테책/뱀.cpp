#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>

#define INF 999999999

using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<vector<int>> res(n+1, vector<int>(n+1));
	int k;
	cin >> k;
	int x, y;
	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;
		res[x][y] = 1; // apple
	}
	int move;
	cin >> move;
	vector<pair<int, char>> direction;
	int sec;
	char dir;
	for (int i = 0; i < move; i++)
	{
		cin >> sec >> dir;
		direction.push_back({ sec, dir });
	}

	int dx[4] = { 0,1,0,-1 }; // 동 남 서 북
	int dy[4] = { 1,0,-1,0 };

	auto turn = [](int pos, char c) {
		if (c == 'L')
			pos = (pos - 1) % 4;
		else
			pos = (pos + 1) % 4;
		if (pos == -1)
			pos = 3;
		return pos;
	};

	x = 1, y = 1;
	res[x][y] = 2; // 뱀의 시작위치
	int init_dir = 0; // 동쪽
	sec = 0; // 0초
	int idx = 0;
	queue<pair<int, int>> snail;
	snail.push({ x,y });



	while (true)
	{
		int nx = x + dx[init_dir];
		int ny = y + dy[init_dir];

		if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && res[nx][ny]!=2)
		{
			if (res[nx][ny] == 0)
			{
				res[nx][ny] = 2; // 뱀 이동

				snail.push({ nx,ny });
				auto prev = snail.front();
				res[prev.first][prev.second] = 0; // 이전 위치 0으로
				snail.pop();
			}
			if (res[nx][ny] == 1) // 사과라면 꼬리 유지
			{
				res[nx][ny] = 2;
				snail.push({ nx,ny });
			}

		}
		else // 부딪힌다면
		{
			sec++;
			break;
		}

		x = nx;
		y = ny;
		sec++;
		if (idx < move && direction[idx].first == sec) // 방향 전환만큼 계싼
		{
			init_dir = turn(init_dir, direction[idx].second);
			idx++;
		}



	}


	cout << sec << endl;



	
}

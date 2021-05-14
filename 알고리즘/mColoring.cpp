#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>

using namespace std;

int color[10];
int graph[10][10];
int m; // 칠할 수 있는 수
int n; // 그래프 내 정점의 수

bool mcoloring_promising(int i)
{
	int j;
	bool flag = true;
	j = 0;
	while (j < i && flag)
	{
		if (graph[i][j] && color[i] == color[j]) // 인접하다면
			return false;
		j++;
	}
	return flag;
}

void mcoloring(int i)
{
	int col;

	if (mcoloring_promising(i))
	{
		if (i == n) // 모두 검사 했다면
		{
			for (auto j : color)
				if (j != 0)
					cout << j << " ";
			cout << endl;
		}
		else
		{
			for (col = 1; col <= m; col++)
			{
				color[i + 1] = col;
				mcoloring(i + 1);
			}
		}
	}
}

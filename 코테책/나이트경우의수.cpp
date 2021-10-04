#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main()
{

	int n;
	char ch;
	cin >> n >> ch;
	map<char, int> db;
	for (char c = 'a'; c <= 'h'; c++)
		db[c] = c - 'a' + 1;
	pair<int, int> res(n, db[ch]);

	int dx[] = { -2,-2,2,2,1,-1,1,-1 };
	int dy[] = { 1,-1,1,-1,2,2,-2,-2 };
	int len = sizeof(dx) / sizeof(int);
	int nx;
	int ny;
	int cnt = 0;
	for (int i = 0; i < len; i++)
	{
		nx = res.first + dx[i];
		ny = res.second + dy[i];
		if (nx<1 || nx>len || ny<1 || ny>len)
			continue;
		else
			cnt++;
	}

	cout << cnt << endl;
	

}

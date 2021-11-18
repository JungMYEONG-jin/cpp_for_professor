#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <cmath>

#define INF 999999999

using namespace std;


bool is_prime(int n)
{
	if (n < 2)
		return false;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}



int main()
{
	
	int t;
	cin >> t;

	vector<int> res;
	for (int i = 1000; i <= 9999; i++)
	{
		if (is_prime(i))
			res.push_back(i);
	}
	bool visited[10000];
	auto get_differ_cnt = [](int e, int k) {
		
	
		int cnt = 0;
	
		while (e)
		{
			int x = e % 10;
			int y = k % 10;
			cnt = x != y ? cnt + 1 : cnt; // 다르면 카운트해줌
			e /= 10;
			k /= 10;
			
			
		}
		return cnt;
	};



	while (t)
	{
		int a, b;
		cin >> a >> b;
		memset(visited, false, sizeof(visited));

		queue<pair<int, int>> q;
		q.push({ a, 0 });
		visited[a] = true;
		//bool flag = false;
		int total = 0;
		while (!q.empty())
		{
			auto it = q.front();
			q.pop();
			int x = it.first;
			int cnt = it.second;
			if (x == b)
			{
				total = cnt;
				//flag = true;
			}
			
			//cout << x << endl;
			for (const auto num : res)
			{
				
				if (get_differ_cnt(x, num) == 1 && !visited[num])
				{
					q.push({ num, cnt + 1 });
					visited[num] = true;

				}
			}
			

		}

		if (visited[b])
			cout << total << endl;
		else
			cout << "Impossible" << endl;


		t--;
	}

	
	

}

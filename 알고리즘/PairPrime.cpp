#include <cmath>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 50

int left_arr[MAX];
int right_arr[MAX];
int left_idx;
int right_idx;
bool visited[MAX];
int left_match[MAX];
int right_match[MAX];

int val;



bool isPrime(int a)
{
	if (a <= 1)
		return false;
	for (int i = 2; i <= sqrt(a); i++)
		if (a % i == 0)
			return false;
	return true;
}


bool dfs(int idx)
{
	if (visited[idx])
		return false;

	visited[idx] = true;

	for (int i = 0; i < right_idx; i++)
	{
		if (i == val)
			continue;


		if (isPrime(left_arr[idx] + right_arr[i]) && (right_match[i] == -1 || !visited[right_match[i]] && dfs(right_match[i])))
		{
			right_match[i] = idx;
			left_match[idx] = i;
			return true;
		}
	}
	return false;


}


int main()
{
	int arr[MAX];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		if (arr[0] % 2 == arr[i] % 2)
			left_arr[left_idx++] = arr[i];
		else
			right_arr[right_idx++] = arr[i];
	}

	set<int> res;
	for (int i = 0; i < right_idx; i++)
	{
		if (isPrime(left_arr[0] + right_arr[i]))
		{
			val = i;
			int count = 1;

			fill(left_match, left_match + MAX, -1);
			fill(right_match, right_match + MAX, -1);
			for (int j = 1; j < left_idx; j++)
			{
				fill(visited, visited + MAX, false);
				if (dfs(j))
					count++;
			}


			if (count == N / 2)
				res.insert(right_arr[i]);



		}
	}
	if (res.size() == 0)
		cout << -1 << endl;
	else
		for (auto i : res)
			cout << i << " ";


}

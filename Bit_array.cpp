#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <bitset>
using namespace std;

int main(int argc, char* argv[])
{
	
	 
	long n;
	uint32_t s, p, q;

	cin >> n >> s >> p >> q;
	uint32_t m = pow(2, 31);
	vector<uint32_t> arr;
	arr.resize(n);
	s = s % m;
	arr[0] = s;
	uint32_t temp = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		s = (s * p + q) % m;
		arr[i] = s;
		
	}
	int c = 0;

	for (int i = 0; i < n - 1; i++)
	{
		if (arr[n-1] != arr[i])
		{
			c = n;
			
		}
		if (arr[n-1] == arr[i])
		{
			c = i+1;
			break;
		}
	}

	cout << c << endl;

	
	/*

	auto iter = find(arr.begin(), arr.end(), arr[0]);
	
	//sort(arr.begin(), arr.end());
	arr.erase(arr.begin(), iter);

	
	cout << arr.size() << endl;
	*/
	
	
	return 0;
	




}

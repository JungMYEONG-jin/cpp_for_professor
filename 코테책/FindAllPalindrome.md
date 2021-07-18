# input 파일에서 모든 회문 찾기

```c++
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

#pragma warning (disable: 4996)



using namespace std;


int countPS(string& str, vector<string>& res)
{
	int n = str.size();
	vector<vector<int>> dp(n, vector<int>(n));
	
	vector<vector<bool>> P(n, vector<bool>(n));
	

	for (int i = 0; i < n; i++)
		P[i][i] = true;

	for (int i = 0; i < n - 1; i++)
	{
		if (str[i] == str[i + 1])
		{
			P[i][i + 1] = true;
			dp[i][i + 1] = 1;
			res.push_back(str.substr(i, 2));
		}
	}

	for (int gap = 2; gap < n; gap++)
	{
		for (int i = 0; i < n - gap; i++)
		{
			int j = gap + i;
			if (str[i] == str[j] && P[i + 1][j - 1])
			{
				P[i][j] = true;
				res.push_back(str.substr(i, j-i+1));
			}

			if (P[i][j])
				dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1 - dp[i + 1][j - 1];
			else
				dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
		}
	}
	
	return dp[0][n - 1];
}








int main()
{

	ofstream fout("output.txt");
	ifstream input("input4.txt");

	string inputstr;
	getline(input, inputstr);
	vector<string> res;
	int num = stoi(inputstr);
	for (int i = 0; i < num; i++)
	{
		fout << "#" << i + 1 << " ";
		res.clear();
		getline(input, inputstr);
		int count = countPS(inputstr, res);
		
		if (count > 0)
		{
			for (auto i : res)
				fout << i << ", ";
		}

		fout << "Count: " << count << endl;
	}



	fout.close();
	input.close();
	

}

```


# Input

```
6
IAEFGSADAOFSOSPIPOKTOOTSCIVIC
SQLANGUAGEOFCOMPUTER
SOFTWAREPROGRAMING
NETWORKSECURITY
DATAMININGSTUDY
ILOVECOMPUTER
```


# Output
```
#1 OO, ADA, SOS, PIP, IVI, TOOT, CIVIC, Count: 7
#2 Count: 0
#3 Count: 0
#4 Count: 0
#5 ATA, INI, NIN, Count: 3
#6 Count: 0
```


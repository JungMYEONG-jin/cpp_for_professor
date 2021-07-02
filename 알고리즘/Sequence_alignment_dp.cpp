#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int dna = 0;
string x;
string y;

int dna_seq(int i, int j)
{
	if (i == x.size())
		dna = 2 * (y.size() - j);
	else if (j == y.size())
		dna = 2 * (x.size() - i);
	else {
		int pen = 0;
		if (x[i] == y[j])
			pen = 0;
		else
			pen = 1;
		dna = min(dna_seq(i + 1, j + 1) + pen, min(dna_seq(i + 1, j) + 2, dna_seq(i, j + 1) + 2));
	}

	return dna;
}



int main()
{

	int n = 690;
	vector<int> money{ 10,45,50,100,500 };
	vector<int> coin(n+1, 1000);

	coin[0] = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = money[i]; j <= 690; j++)
		{
			coin[j] = min(coin[j], coin[j - money[i]] + 1);
		}
	}
	
	string x2;
	string y2;
	cin >> x2 >> y2;

	int len1 = x2.size();
	int len2 = y2.size();

	vector<vector<int>> dp(len1+1, vector<int>(len2+1));

	for (int i = 0; i <= len1; i++)
		dp[i][0] = 2 * i;

	for (int j = 0; j <= len2; j++)
		dp[0][j] = 2 * j;



	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (x2[i - 1] == y2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(dp[i - 1][j - 1]+1, min(dp[i - 1][j] + 2, dp[i][j - 1] + 2));
		}
	}

	int l = len1 + len2;

	int left = len1;
	int right = len2;

	int xpos = l;
	int ypos = l;

	vector<int> xans(l + 1);
	vector<int> yans(l + 1);

	while (!(left == 0 || right == 0))
	{
		if (x2[left - 1] == y2[right - 1])
		{
			xans[xpos--] = (int)x2[left - 1];
			yans[ypos--] = (int)y2[right - 1];
			left--;
			right--;
		}
		else if (dp[left - 1][right - 1] + 1 == dp[left][right])
		{
			xans[xpos--] = (int)x2[left - 1];
			yans[ypos--] = (int)y2[right - 1];
			left--;
			right--;
		}
		else if (dp[left - 1][right] + 2 == dp[left][right])
		{
			xans[xpos--] = (int)x2[left - 1];
			yans[ypos--] = (int)'_';
			left--;
		}
		else if (dp[left][right - 1] + 2 == dp[left][right])
		{
			xans[xpos--] = (int)'_';
			yans[ypos--] = (int)y2[right - 1];
			right--;
		}




	}



	while (xpos > 0)
	{
		if (left > 0)
			xans[xpos--] = (int)x2[--left];
		else
			xans[xpos--] = (int)'_';
	}


	while (ypos > 0)
	{
		if (right > 0)
			yans[ypos--] = (int)y2[--right];
		else
			yans[ypos--] = (int)'_';
	}

	int id = 1;
	for (int k = l; k >= 1; k--)
	{
		if ((char)yans[k] == '_' && (char)xans[k] == '_')
		{
			id = k + 1;
			break;
		}
	}



	cout << dp[len1][len2] << endl;

}

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void return_permutation(string str)
{
	sort(str.begin(), str.end());


	do
	{
		cout << str << endl;
	} while (next_permutation(str.begin(), str.end()));


}


bool isMobile(int, string, const vector<int>&);

bool CheckMobiles(string str, const vector<int>& directions)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (isMobile(i, str, directions))
			return true;
	}
	return false;
}

bool isMobile(int p, string str, const vector<int>& directions)
{
	if (p == 0 && directions[p] == 0)
		return false;
	else if (p == str.size() - 1 && directions[p] == 1)
		return false;
	else
	{
		if (directions[p] == 0) //left move가 가능
		{
			if (str[p] > str[p - 1])
				return true;
		}
		else
		{
			if (str[p] > str[p + 1])
			{
				return true;
			}
		}
	}
	return false;  // 그외 모두 false
}


int FindLargest(string str, const vector<int>& directions)
{

	vector<int> MobileNum;

	for (int i = 0; i < str.size(); i++)
	{
		if (isMobile(i, str, directions))
			MobileNum.push_back(i); //움직일수 있는 모든 수에 대한 인덱스 찾음
	}


	int LasrgestNum = MobileNum[0];


	for (int p = 1; p < MobileNum.size(); p++)
	{
		if (str[MobileNum[p]] > LasrgestNum)
			LasrgestNum = MobileNum[p];
	}




	return LasrgestNum;

}


void print_without_recursive(string str)
{
	int k;
	vector<int> directions;


	sort(str.begin(), str.end());

	for (const auto& i : str)
	{
		directions.push_back(0);
	}


	cout << str << endl;

	while (CheckMobiles(str, directions))
	{
		k = FindLargest(str, directions);
		if (directions[k] == 0)
		{
			swap(str[k], str[k - 1]);
			swap(directions[k], directions[k - 1]);
			k = k - 1;
		}
		else
		{
			swap(str[k], str[k+1]);
			swap(directions[k], directions[k+1]);
			k = k + 1;
		}

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] > str[k])
			{
				if (directions[i] == 0)
				{
					directions[i] = 1;
				}
				else
				{
					directions[i] = 0;
				}
			}
		}

	}

	cout << str << endl;



}

void next_permutation(std::string str, std::string perm)
{
	if (str.empty()) std::cout << perm << std::endl;
	else
	{
		for (size_t i = 0; i < str.size(); ++i)
		{
			next_permutation(str.substr(1), perm + str[0]);

			std::rotate(std::begin(str), std::begin(str) + 1, std::end(str));
		}
	}
}

void print_permutations_recursive(std::string str)
{
	next_permutation(str, "");
}




int main()
{

	return_permutation("apple");
	cout << endl;

	print_permutations_recursive("apple");


}
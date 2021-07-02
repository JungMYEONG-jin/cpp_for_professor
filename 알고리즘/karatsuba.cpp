#include <vector>
#include <iostream>

using namespace std;

void normalize(vector<int>& num)
{
	num.push_back(0);


	int len = num.size();
	for (int i = 0; i < len - 1; i++)
	{
		if (num[i] < 0)
		{
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else
		{
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while (num.size() > 1 && num.back() == 0)
	{
		num.pop_back();
	}


}


vector<int> multiply(const vector<int>& a, const vector<int>& b)

{

	vector<int> c(a.size() + b.size() + 1, 0);

	for (int i = 0; i < a.size(); i++)

		for (int j = 0; j < b.size(); j++)

			c[i + j] += (a[i] * b[j]);

	normalize(c);

	return c;

}



void add(vector<int>& a, const vector<int>& b, int k)

{

	int length = b.size();

	a.resize(max(a.size() + 1, b.size() + k));



	for (int i = 0; i < length; i++)

		a[i + k] += b[i]; //이렇게 함으로써 굳이 다른 vector를 선언하지 않아도 되고 간편해졌다



 //정규화              

	for (int i = 0; i < a.size(); i++)

	{

		if (a[i] >= 10)

		{

			a[i + 1] += a[i] / 10;

			a[i] %= 10;

		}

	}

}



//a-=b;를 구현한다 a>=b를 가정한다

void sub(vector<int>& a, const vector<int>& b)

{

	int length = b.size();

	a.resize(max(a.size() + 1, b.size()) + 1);



	for (int i = 0; i < length; i++)

		a[i] -= b[i];



	//정규화

	for (int i = 0; i < a.size(); i++)

	{

		if (a[i] < 0)

		{

			a[i] += 10;

			a[i + 1] -= 1;

		}

	}

}



vector<int> karatsuba(const vector<int>& left, const vector<int>& right)
{
	int len1 = left.size();
	int len2 = right.size();

	if (len1 < len2)
		return karatsuba(right, left); // 항상 왼쪽이 더커야함

	if (len1 == 0 || len2 == 0)
		return {};

	if (len1 <= 5)
		return multiply(left, right);


	int half = len1 / 2;
	vector<int> a0(left.begin(), left.begin() + half);
	vector<int> a1(left.begin() + half, left.end());
	vector<int> b0(right.begin(), right.begin() + min(half, len2));
	vector<int> b1(right.begin() + min(half, len2), right.end());

	//z2 = a1*b1
	vector<int> z2 = karatsuba(a1, b1);
	//z0 = a0*b0
	vector<int> z0 = karatsuba(a0, b0);

	//a0 = a0+a1
	add(a0, a1,0);
	//b0 = b0+b1
	add(b0, b1, 0);
	//z1 = (a0+a1)*(b0+b1) - z0 - z2
	vector<int> z1 = karatsuba(a0, b0);
	sub(z1, z0);
	sub(z1, z2);
	// res = z0+z1*10^half+z2*10^(half*2)
	vector<int> res;
	add(res, z0, 0);
	add(res, z1, half);
	add(res, z2, half + half);
	return res;
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
	/*
	string x2;
	string y2;
	cin >> x2 >> y2;

	

	int len1 = x2.size();
	int len2 = y2.size();
	vector<vector<int>> dp;
	sequence_alignment(x2, y2, dp);



	cout << dp[len1][len2] << endl;
	*/

	string number;
	cin >> number;
	vector<int> left;
	for (int i = number.size() - 1; i >= 0; i--)
		left.push_back(number[i] - '0');
	cin >> number;
	vector<int> right;
	for (int i = number.size() - 1; i >= 0; i--)
		right.push_back(number[i] - '0');



	auto res = multiply(left, right);

	reverse(res.begin(), res.end());
	for (auto i : res)
		cout << i;
	cout << endl;

	res.clear();

	res = karatsuba(left, right);
	reverse(res.begin(), res.end());
	int idx = 0;
	for (int i = 0; i < res.size(); i++)
	{
		if (res[0] == 0)
		{
			while (res[idx] == 0)
				idx++;
			break;
		}
		else
			break;
	}
	
	res.erase(res.begin(), res.begin() + idx);



	for (auto i : res)
		cout << i;
	cout << endl;



}

# 주민번호가 유효한지 검증하는 프로그램

```c++

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

#pragma warning (disable: 4996)



using namespace std;


class Enemy
{
public:
	Enemy(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	
	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}


private:
	int x, y;

};



class Rader
{
public:

	Rader() {};

	void setPoint(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void setRadius(int r)
	{
		this->r = r;
	}


	Rader(int x, int y, int r)
	{
		this->x = x;
		this->y = y;
		this->r = r;
	}

	~Rader() {};

	bool check(Enemy& e)
	{
		int x1 = x - e.getX();
		int y1 = y - e.getY();
		bool res = false;
		if (sqrt(pow(x1, 2) + pow(y1, 2) + 0.0) <= r)
		{
			res = true;
		}
		return res;

	}

private:
	int x;
	int y;
	int r;
};











int main()
{

	ofstream fout("output.txt");
	ifstream input("input2.txt");

	string inputstr;
	getline(input, inputstr);
	int num = stoi(inputstr);

	vector<string> regions = { "000001", "000010", "000100", "001000", "010000", "100000" };

	auto checksum = [&regions,&fout](auto e) {
		if (e.size() != 18)
		{
			fout << "Invalid" << endl;
			return false;
		}
		
		string region = e.substr(0, 6);
		if (find(regions.begin(), regions.end(), region) == regions.end()) // check region code
		{
			fout << "Invalid" << endl;
			return false;
		}
		string birth = e.substr(6, 8);
		if (stoi(birth) < 19000101 || stoi(birth) > 20141231) // check birthday
		{
			fout << "Invalid" << endl;
			return false;
		}

		string orderCode = e.substr(14, 3);
		string sex;
		int k = stoi(orderCode);
		if (k == 0)
		{
			fout << "Invalid" << endl;
			return false;
		}
		else
		{
			if (k % 2 == 1)
				sex = "Male";
			else
				sex = "Female";
		}
		
		string checkCode = string(1,e.back());
		long long sum = 0;
		for (int i = 0; i < 17; i++)
		{
			sum += pow(2, 17 - i) * (e[i]-'0');
		}
		cout << sum << endl;
		sum %= 11;
		cout << sum << endl;
		cout << checkCode << endl;

		

		if (sum == 10)
		{
			if (checkCode == "X")
				fout << sex << endl;
			else
				fout << "Invalid" << endl;
		}
		else
		{
			string k = to_string(sum);
			if (checkCode == k)
				fout << sex << endl;
			else
				fout << "Invalid" << endl;
		}



	};

	for (int i = 0; i < num; i++)
	{
		getline(input, inputstr);
		cout << inputstr <<" "<<inputstr.size()<<endl;
		checksum(inputstr);
	}

	fout.close();
	input.close();
	

}



```

# Input
```
6
010000200312060638
000010201207270625
001000199907271230
000010201207270625
10000020100727890X
100000201007278904
```



# Output
```
Male
Female
Male
Female
Invalid
Female
```

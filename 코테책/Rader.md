# 레디어 탐지 프로그램 만들기
# input 파일을 읽어와 output 파일로 return하기 구현

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
	ifstream input("input.txt");

	Rader rader;

	int testnum;
	int x, y, r;
	string inputstr;
	string inputstr2;
	int i;
	int num, count = 0;
	getline(input, inputstr);
	testnum = stoi(inputstr);
	char* str;
	for (int j = 0; j < testnum; j++)
	{

		getline(input, inputstr);
		getline(input, inputstr2);
		cout << inputstr << endl;
		cout << inputstr2 << endl;
		count = 0;
		str = (char*)inputstr.c_str();
		x = atoi(strtok(str, " "));
		y = atoi(strtok(NULL, " "));
		r = atoi(strtok(NULL, " "));
		num = atoi(strtok(NULL, " "));
		rader.setPoint(x, y);
		rader.setRadius(r);
		cout << "#" << j + 1 << endl;
		fout << "#" << j + 1 << " ";
		str = (char*)inputstr2.c_str();
		for (i = 0; i < num; i++)
		{
			if (i == 0)
			{
				x = atoi(strtok(str, " "));
				y = atoi(strtok(NULL, " "));
			}
			else
			{
				x = atoi(strtok(NULL, " "));
				y = atoi(strtok(NULL, " "));

			}
			Enemy e(x, y);
			if (rader.check(e))
				count++;
		
		}
		fout << count << endl;
	}


	input.close();
	fout.close();
	return 0;

}


```


# Input
```
5
5 5 3 7
1 3 2 5 4 4 3 8 3 5 5 7 6 8
30 59 10 10
17 31 28 29 31 38 44 34 51 25 63 36 71 47 82 38 91 29 60 30
8 17 5 7
1 17 2 16 13 7 24 5 15 8 26 6 7 24
7 8 6 5
5 1 4 2 3 7 4 6 5 6
11 6 8 7
6 7 7 6 10 7 11 5 2 17 9 6 7 14
```

# Output
```
#1 4
#2 0
#3 0
#4 3
#5 5
```

#include <cmath>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

const int MAX = 1000000000;

using namespace std;



int main()
{
	int T;
	map<int, int> m1;
	cin >> T;
	long long x;
	for (int i = 0; i < T; i++)
	{
		cin >> x;
		long j = 2;
		while (j*j<=x)
		{
			while (x % j == 0)
			{
				x /= j;
				m1[j]++;
			}
			j++;
		}
		m1[x]++;
	}
	map<int, int> m2;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> x;
		long j = 2;
		while (j * j <= x)
		{
			while (x % j == 0)
			{
				x /= j;
				m2[j]++;
			}
			j++;
		}
		m2[x]++;
	}
    bool over = false;
	long long mul = 1;
	for (auto& it : m1)
	{
		int k = it.first;
		int p = it.second;
        int min_count=0;
		if (m2.find(it.first) != m2.end())
		{
			min_count=min(p, m2[k]); 
            while(min_count>0)
            {
                mul*=k;
                if(mul>MAX)
                {
                    over=true;
                    mul%=MAX;
                }
                min_count--;
            }
		}
	}

    if(over)
    {
        cout.width(9);
        cout.fill('0');
        cout<<mul<<endl;
    }else
        cout<<mul<<endl;
	



}

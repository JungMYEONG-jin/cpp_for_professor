#include <iostream>
#include <vector>
using namespace std;



void draw_pascal(int row)
{
	

	for (int i = 1; i <= row; i++)
	{
		
		int c = 1;
		for (int j = 1; j <= i; j++)
		{
			cout << c << " ";
			c =c* (i - j) / j;
		}
		
		cout << endl;
	}


}

// book code

unsigned int number_of_digits(unsigned int const i)
{
	return i > 0 ? (int)log10((double)i) + 1 : 1;
}

void print_pascal_triangle(int const n)
{
	

	for (int i = 0; i < n; i++)
	{
		auto x = 1;
		cout << string((n - i - 1) * (n / 2), ' ');
		for (int j = 0; j <= i; j++)
		{
			auto y = x;
			x = x*(i - j) / (j + 1);
			auto maxlen = number_of_digits(x) - 1;
			cout << y << string(n - 1 - maxlen - n % 2, ' ');
		}
		cout << endl;
	}
}



int main()
{
	draw_pascal(5);
	print_pascal_triangle(5);
}
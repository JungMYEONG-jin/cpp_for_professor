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


	
	x = "AACAGTTACC";
	y = "TAAGGTCA";

	cout << dna_seq(0, 0);



}

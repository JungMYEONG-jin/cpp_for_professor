#include <iostream>
#include <random>

using namespace std;

int main()
{

	// shuffling algorithm


	int cards[52];

	for (int i = 0; i < 52; i++)
		cards[i] = i + 1;

	cout << "섞기전 카드 배열\n";
	for (int i = 0; i < 52; i++)
		cout << cards[i] << " ";
	cout << endl;

	/*
	for (int i = 0; i < 52; i++)
	{
		int r = i + rand() % (52 - i);
		swap(cards[i], cards[r]);
	}
	*/

	/*
	for (int i = 51; i >= 0; i--)
	{
		int r = rand() % (i + 1);
		swap(cards[i], cards[r]);
	}
	*/

	//using random device

	random_device rd;
	mt19937 gen(rd());

	for (int i = 51; i >= 0; i--)
	{
		uniform_int_distribution<decltype(i)> dist(0, 51);
		swap(cards[i], cards[dist(gen)]);
	}

	cout << "섞은후 카드 배열\n";
	for (int i = 0; i < 52; i++)
		cout << cards[i] << " ";
	cout << endl;

  
}


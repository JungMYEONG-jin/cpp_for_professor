#include <random>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;


std::string generateName()
{
	// make sure to check the name is unique via the photoManager object
	string const allowed = "ABCDEFGHIGKLMNOPQRSTUVWXYZ";
	//abcdefghijklmnopqrstuvwxyz

	random_device rd;
	auto seed_data = array<int, std::mt19937::state_size>{};
	generate(seed_data.begin(), seed_data.end(), std::ref(rd));
	std::seed_seq seq(seed_data.begin(), seed_data.end());
	mt19937 mt;
	mt.seed(seq);
	uniform_int_distribution<> chardist(0, 25);
	string res;
	for (int i = 0; i < 6; i++)
	{
		res += allowed[chardist(mt)];
	}
	return res;
}

int main()
{

	for (int i = 0; i < 10; i++)
		cout << generateName() << endl;


}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>
using namespace std;


struct movie
{
	string name;
	int score;

};

double get_movie_review_score(vector<movie>& data, double percentage)
{
	double tot_mean = 0;





	sort(data.begin(), data.end(), [](auto const& k, auto const& p) {
		return k.score < p.score;
		});




	size_t erase_range = static_cast<size_t>(data.size() * percentage + 0.5);

	data.erase(data.begin(), data.begin() + erase_range);
	data.erase(data.end() - erase_range, data.end());


	int sum = 0;
	for (auto& it : data)
		sum += it.score;

	tot_mean = static_cast<double>(sum) / data.size();



	auto total = accumulate(data.begin(), data.end(), 0ull, [](auto sum, auto const& k) {
		return sum += k.score;
		});


	return static_cast<double>(total) / data.size();

}



void print_movie(vector<movie>& data)
{

	for (auto const& e : data)
	{
		cout << e.name << setw(5) << right << setfill(' ') << e.score << setw(2) << right << setfill(' ') << "   " << fixed << setprecision(1) << get_movie_review_score(data, 0.05) << endl;
	}


}


int main()
{

	vector<movie> test{ {"City",9}, {"Furious", 6}, {"Harry", 4} };

	cout << fixed << setprecision(1) << get_movie_review_score(test, 0.05) << endl;

	print_movie(test);



}


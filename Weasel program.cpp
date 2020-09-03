#include <string>
#include <map>
#include <random>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <array>
#include <string_view>
using namespace std;


class Weasel
{
	std::mt19937 mt;
	std::string target;
	std::uniform_int_distribution<> chardist;
	std::uniform_real_distribution<> ratedist;
	string  const allowed_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

public:


	Weasel(string_view t)
		:target(t), chardist(0, 26), ratedist(0, 100)
	{
		std::random_device rd;
		auto seed_data = array<int, std::mt19937::state_size>{};
		generate(seed_data.begin(), seed_data.end(), std::ref(rd));
		std::seed_seq seq(seed_data.begin(), seed_data.end());
		mt.seed(seq);
	}



	void run(int const copies)
	{
		int step = 1;
		auto parent = make_random();
		cout << left << setw(5) << setfill(' ') << step << parent << endl;


		

		do
		{
			vector<string> child;
			std::generate_n(back_inserter(child), copies, [parent, this]() {return mutate(parent, 5); });


			parent = *max_element(child.begin(), child.end(), [this](string_view const k, string_view const p) {return fitness(k) < fitness(p); });
			
			cout << setw(5) << setfill(' ') << step << parent << endl;
			step++;
		} while (parent != target);


	}





private:

	Weasel() = delete;

	string make_random()
	{
		stringstream sstr;
		for (int i = 0; i <target.size(); i++)
		{
			sstr << allowed_chars[chardist(mt)];

		}
		return sstr.str();
	}

	double fitness(string_view candidate)
	{
		double score = 0;
		for (int i = 0; i < candidate.size(); i++)
		{
			if (target[i] == candidate[i])
				score++;
		}
		return score;
	}

	string mutate(string_view text, double const percent)
	{
		stringstream sstr;
		for (auto c : text)
		{
			auto nc = ratedist(mt) > percent ? c : allowed_chars[chardist(mt)];
			sstr << nc;
		}
		return sstr.str();
	}


};



int main()
{
	Weasel w("METHINKS IT IS LIKE A WEASEL"); //족제비 프로그램 구현하기
	w.run(100);
	
	

}
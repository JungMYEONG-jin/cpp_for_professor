#include <regex>
#include <string>
#include <iostream>
#include <mutex>
#include <random>
#include <array>
#include <unordered_map>
#include <map>

using namespace std;


bool spell_check(string pass)
{
	bool low = false;
	bool upp = false;
	bool digit = false;
	if (pass.find_first_of("abcdefghijklmnopqrstuvwxyz") != pass.npos)
		low = true;
	if (pass.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != pass.npos)
		upp = true;
	if (pass.find_first_of("0123456789") != pass.npos)
		digit = true;

	if (low && upp && digit)
		return true;
	else
		return false;
}

string pass()
{
	random_device rd;
	mt19937 eng;
	auto seed_data = array<int, std::mt19937::state_size>{};

	std::generate(begin(seed_data), end(seed_data), ref(rd));

	std::seed_seq seq(begin(seed_data), end(seed_data));
	eng.seed(seq);

	string pass = "";
	string allowed = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

	uniform_int_distribution<> ud(6, 20);
	uniform_int_distribution<> pd(0, allowed.size() - 1);


	for (int i = 0; i < ud(eng); i++)
	{
		pass += allowed[pd(eng)];


	}
	return pass;
}

std::string password_gen() {

	string res = pass();

	while (!spell_check(res))
		res = pass();
	return res;



}


std::string work_on_strings(const std::string& a, const std::string& b) {

	map<char, int> res1;

	map<char, int> res2;

	string t_a = a;
	string t_b = b;


	for (auto i = 'a'; i <= 'z'; i++)
	{
		res1[i] = 0;
		res2[i] = 0;
	}

	for (auto& i : a)
	{
		res1[tolower(i)]++;
	}
	for (auto& i : b)
	{
		res2[tolower(i)]++;
	}


	for (auto& it : res1)
	{
		int count = it.second;

		if (res2.find(it.first) != res2.end())
		{
			if (count % 2 != 0)
			{

				for (int i = 0; i < t_b.size(); i++)
				{
					if (islower(t_b[i]) && t_b[i] == it.first)
					{
						t_b[i] = toupper(t_b[i]);

					}
					else if (isupper(t_b[i]) && t_b[i] == toupper(it.first))
						t_b[i] = tolower(t_b[i]);
				}
			}
		}

	}

	for (auto& it : res2)
	{
		int count = it.second;

		if (res1.find(it.first) != res1.end())
		{
			if (count % 2 != 0)
			{
				//for (int i = 0; i < t_a.size(); i++)
				//{
					//if (t_a[i] == it.first)
						//t_a[i] = tolower(t_a[i]);
				//}

				for (int i = 0; i < t_a.size(); i++)
				{
					if (islower(t_a[i]) && t_a[i] == it.first)
					{
						t_a[i] = toupper(t_a[i]);

					}
					else if (isupper(t_a[i]) && t_a[i] == toupper(it.first))
						t_a[i] = tolower(t_a[i]);
				}
			}
		}


	}


	return t_a + t_b;



}



int main()
{
	cout << work_on_strings("abc", "cde") << endl;
	cout << work_on_strings("ab", "aba") << endl;
	cout << work_on_strings("abcdeFgtrzw", "defgGgfhjkwqe") << endl;
	cout << work_on_strings("abcdeFg", "defgG") << endl;
	cout << work_on_strings("abab", "bababa") << endl;
}
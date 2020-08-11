#include <iostream>
#include <numeric>
#include <string>
#include <filesystem>
#include <chrono>
#include <regex>
using namespace std;


namespace fs = std::filesystem;



//MY CODE
using namespace std::string_literals;
bool is_reg(fs::path const& p1)
{
	auto match = smatch{};
	auto str = p1.filename().string();
	regex re{ R"(([a-zA-Z0-9°¡-ÆR\s_+.-]+).(\w+))" };
	if (regex_match(str, match, re))
	{
		return true;
	}
	return false;
}

vector<string> reg_file_list(fs::path const& p1)
{
	vector<string> res{};
	for (auto const& s : fs::directory_iterator(p1))
		if (is_reg(s))
			res.push_back(s.path().filename().string());

	return res;


}


//BOOK CODE

vector<fs::directory_entry> find_files(fs::path const& p1, string_view reg)
{



	vector<fs::directory_entry> res{};

	regex rx(reg.data());

	
	copy_if(fs::recursive_directory_iterator(p1), fs::recursive_directory_iterator(), back_inserter(res), [&rx](fs::directory_entry const& entry)
		{return fs::is_regular_file(entry.path()) && regex_match(entry.path().filename().string(), rx); });

	return res;








}










int main()
{
	

	fs::path str = fs::current_path();

	auto k = reg_file_list(str);

	for (auto const& p : k)
		cout << p << endl;

	auto dir = fs::temp_directory_path();

	string_view re = R"(wct[0-9a-zA-Z]{3}\.tmp)";

	auto res = find_files(dir, re);

	for (auto const& o : res)
		cout << o.path().filename().string() << endl;



}

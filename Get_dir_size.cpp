#include <iostream>
#include <numeric>
#include <string>
#include <filesystem>


using namespace std;

namespace fs = std::filesystem;



uintmax_t get_directory_size(fs::path const& dir, bool symlink = false)
{

	auto iter = fs::recursive_directory_iterator(dir, symlink ? fs::directory_options::follow_directory_symlink : fs::directory_options::none);
	// symlink check

	return accumulate(begin(iter), end(iter), 0ull, [](uintmax_t const total, fs::directory_entry const& p1) {
		return total + (fs::is_regular_file(p1) ? fs::file_size(p1.path()) : 0);
		});



}


int main()
{
	string path;
	cout << "Path: ";
	cin >> path;
	// type the path then show directory file list and return size
	for (auto const& p1 : fs::recursive_directory_iterator(path))
		cout << p1.path() << endl;
	cout << "size: " << get_directory_size(path) << endl;
}
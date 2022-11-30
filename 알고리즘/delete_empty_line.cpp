#include <vector>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

#define FILESYSTEM_EXPERIMENTAL


using namespace std;

namespace fs = std::filesystem;


void remove_empty_line(fs::path p1)
{

	ifstream readFile(p1.native(), std::ios::in);

	if (!readFile.is_open())
		throw runtime_error("Can not open file");

	auto p2 = fs::temp_directory_path() / "temp_file.txt";

	ofstream writeFile(p2.native(), std::ios::out | std::ios::trunc);
	if (!writeFile.is_open())
		throw runtime_error("Can not create temp file");

	string test;

	while (getline(readFile, test))
	{
		if (test.length() > 0 && test.find_first_not_of(' ') != test.npos)
		{
			writeFile << test << '\n';
		}
	}

	readFile.close();
	writeFile.close();

	fs::remove(p1);
	fs::rename(p2, p1);




}



int main()
{
	remove_empty_line("sample34.txt");
}


#include <string>
#include <vector>
#include <string_view>
#include <filesystem>
#include <iostream>
#include <fstream>
#include "Library/MJ/libs/stduuid/uuid.h"


using namespace std;

namespace fs = std::filesystem;



class Log
{

	fs::path mdir;
	ofstream logfile;



public:
	Log()
	{
		auto name = uuids::to_string(uuids::uuid_random_generator{}());
	
		mdir = fs::temp_directory_path() / (name + ".tmp");

		logfile.open(mdir.c_str(), ios::out | ios::trunc);

	}

	~Log() noexcept
	{
		try
		{
			if (logfile.is_open())
				logfile.close();
			if (!mdir.empty())
				fs::remove(mdir);
		}
		catch (...)
		{

		}
		
	}

	void persist(fs::path const& paths)
	{
		logfile.close();
		fs::rename(mdir, paths);
		mdir.clear();
	}

	Log& operator<<(string_view message)
	{
		logfile << message.data() << '\n';
		return *this;
	}

	
};



int main()
{
	Log log;
	try
	{
		log << "this is a line" << "and this is another one";

		throw std::runtime_error("error");
	}
	catch (...)
	{
		log.persist(R"(lastlog.txt)");




	}

}
#include <iostream>
#include <cstddef>
#include <string>
#include <cstring>
#include <fstream>
#include <exception>



using namespace std;



/*
class Logger
{
public:
	static void enableLogging(bool enable) { mLoggin = enable; }
	static bool isLoggingEnabled() { return mLoggin; }


	template <typename... Args>
	static void log(const Args&... args)
	{
		if (!mLoggin)
			return;


		ofstream logfile(debugFilename, ios_base::app);
		
		if (logfile.fail())
		{
			cerr << "Unable to open File" << endl;
			return;
		}

		((logfile << args), ...);
		logfile << endl;


	}


private:
	static bool mLoggin;
	static const string debugFilename;
};



const string Logger::debugFilename = "debugfile.out";
bool Logger::mLoggin = false;


#define log(...) Logger::log(__func__, "(): ", __VA_ARGS__)

bool isDebugSet(int argc, char* argv[])
{

	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "=d") == 0)
		{
			return true;
		}
	}

	return false;
}

class Complicated
{

};

ostream& operator<<(ostream& out, const Complicated&)
{
	out << "Complicated Class";
	return out;
}




class UserCommand
{

};

ostream& operator<<(ostream& out, const UserCommand&)
{
	out << "UserCommand";
	return out;
}

UserCommand getNext(Complicated*)
{
	UserCommand cmd;
	return cmd;
}

void processUserCommand(UserCommand&)
{

}

void trickyFunction(Complicated* obj)
{
	log("given argument: ", *obj);

	for (size_t i = 0; i < 100; i++)
	{
		UserCommand cmd = getNext(obj);
		log("retrieved cmd ", i, ": ", cmd);

		try {
			processUserCommand(cmd);
		}
		catch (const exception& e)
		{
			log("exception from processUserCommand(): ", e.what());
		}
	}
}





int main(int argc, char* argv[])
{
	Logger::enableLogging(isDebugSet(argc, argv));

	if (Logger::isLoggingEnabled())
	{
		for (int i = 0; i < argc; i++)
		{
			log(argv[i]);
		}
	}

	Complicated obj;
	trickyFunction(&obj);

	return 0;




}



*/
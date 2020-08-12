#include "singleton.h"
#include <iostream>


using namespace std;


const char* const Logger::kFileName = "log.out";

Logger& Logger::instance()
{
	static Logger instance;
	return instance;

}

void Logger::setLoglevel(Loglevel level)
{
	mLoglevel = level;
}

Logger::Logger()
{
	temp_file.open(kFileName, ios_base::app);
	if (!temp_file.good())
		throw runtime_error("Unable to initialize file");
}

Logger::~Logger()
{
	temp_file << "로그 기록을 중단합니다." << '\n';
	temp_file.close();
}

void Logger::log(string_view str, Loglevel level)
{
	if (mLoglevel < level)
		return;
	temp_file << getLogLevel(level).data() << ": " << str << '\n';
}


void Logger::log(const vector<string>& message, Loglevel level)
{

	if (mLoglevel < level)
		return;


	for (const auto& p : message)
		log(p, level);

}


string_view Logger::getLogLevel(Loglevel level) const
{
	switch (level)
	{
	case Loglevel::Error:
		return "Error";
	case Loglevel::Info:
		return "Info";
	case Loglevel::Debug:
		return "Debug";
	
	}
	throw runtime_error("Invalid Loglevel");

}

int main()
{
	Logger::instance().setLoglevel(Logger::Loglevel::Debug);

	Logger::instance().log("test message", Logger::Loglevel::Debug);

	vector<string> res{ "item1", "item2" };

	Logger::instance().log(res, Logger::Loglevel::Error);

	Logger::instance().setLoglevel(Logger::Loglevel::Error);

	Logger::instance().log("A debug message", Logger::Loglevel::Debug);
}
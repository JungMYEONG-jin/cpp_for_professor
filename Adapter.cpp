#include <iostream>
#include "Adapter.h"

using namespace std;

AdapterLogger::AdapterLogger()
{
	cout << "Logger Created" << endl;
}

void AdapterLogger::log(LogLevel level, string str)
{
	cout << getLogLevelToString(level).data() << ": " << str << endl;
}

string_view AdapterLogger::getLogLevelToString(LogLevel level) const
{
	switch (level)
	{
	case AdapterLogger::LogLevel::Error:
		return "Error";
	case AdapterLogger::LogLevel::Info:
		return "Info";
	case AdapterLogger::LogLevel::Debug:
		return "Debug";
	}

	throw runtime_error("Invalid Log Level");
}


NewLoggerAdapter::NewLoggerAdapter()
{
	cout << "New Logger Adapter created" << endl;
}

void NewLoggerAdapter::log(string_view message)
{
	mLogger.log(AdapterLogger::LogLevel::Info, message.data());
}

int main()
{
	NewLoggerAdapter logger;

	logger.log("테스트중이에요");
}
#pragma once
#include <string>
#include <vector>
#include <string_view>
#include <fstream>

class Logger final
{
public:

	enum class Loglevel{Error, Info, Debug};

	static	Logger& instance();

	Logger(const Logger&) = delete;
	Logger(Logger&&) = delete;

	Logger& operator=(const Logger&) = delete;
	Logger& operator=(Logger&&) = delete;

	void setLoglevel(Loglevel level);

	void log(std::string_view message, Loglevel level);

	void log(const std::vector<std::string>& message, Loglevel level);


private:
	Logger();
	~Logger();

	static const char* const kFileName;
	std::ofstream temp_file;
	std::string_view getLogLevel(Loglevel log) const;
	Loglevel mLoglevel = Loglevel::Error;


};
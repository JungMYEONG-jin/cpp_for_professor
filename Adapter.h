#pragma once


#include <string>
#include <string_view>


class AdapterLogger
{
public:
	enum class LogLevel{Error, Info, Debug};

	AdapterLogger();
	virtual	~AdapterLogger() = default;

	void log(LogLevel level, std::string str);
private:
	std::string_view getLogLevelToString(LogLevel level) const;
};


class NewLoggerInterface
{
public:
	virtual ~NewLoggerInterface() = default;
	virtual void log(std::string_view message) = 0;
};

class NewLoggerAdapter : public NewLoggerInterface
{
public:
	NewLoggerAdapter();
	virtual void log(std::string_view message) override;
private:
	AdapterLogger mLogger;
};


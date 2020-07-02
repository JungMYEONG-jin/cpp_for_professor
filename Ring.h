#pragma once



#include <cstddef>
#include <vector>
#include <string>
#include <ostream>
#include <sstream>






class RingBuffer
{
public:

	explicit RingBuffer(size_t numEntries = kDefaultNum, std::ostream* ostr = nullptr);
	virtual ~RingBuffer() = default;


	template <typename... Args>
	void addEntry(const Args&... args)
	{
		std::ostringstream os;
		((os << args), ...);
		addEntry(os.str());
	}

	friend std::ostream& operator<<(std::ostream& ostr, RingBuffer& rb);

	std::ostream* setOutput(std::ostream* newOstr);

private:
	static const size_t kDefaultNum = 500;
	std::vector<std::string> mEntries;
	std::vector<std::string>::iterator mNext;


	std::ostream* mOstr;
	void addStringEntry(std::string&& entry);
	bool mWrapped;

};
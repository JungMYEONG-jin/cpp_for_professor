#include <algorithm>
#include <iterator>
#include <iostream>
#include <utility>
#include <stdexcept>
#include "Ring.h"


using namespace std;

RingBuffer::RingBuffer(size_t numEntries, ostream* ostr)
	:mEntries(numEntries), mOstr(ostr), mWrapped(false)
{
	if (numEntries == 0)
		throw invalid_argument("Number of entries must be > 0");
	mNext = begin(mEntries);
}

void RingBuffer::addStringEntry(string&& entry)
{
	if (mOstr)
	{
		*mOstr << entry << endl;
	}


	*mNext = std::move(entry);
	++mNext;


	if (mNext == end(mEntries))
	{
		mNext = begin(mEntries);
		mWrapped = true;
	}

}



ostream* RingBuffer::setOutput(ostream* newOstr)
{
	return std::exchange(mOstr, newOstr);
}


ostream& operator<<(ostream& ostr, RingBuffer& rb)
{
	if (rb.mWrapped)
	{
		copy(rb.mNext, end(rb.mEntries), ostream_iterator<string>(ostr, "\n"));
	}

	copy(begin(rb.mEntries), rb.mNext, ostream_iterator<string>(ostr, "\n"));

	return ostr;
}











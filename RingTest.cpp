#include "Ring.h"
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>


using namespace std;

RingBuffer debugBuf;

#define log(...) debugBuf.addEntry(__func__, "(): ", __VA_ARGS__)


class Complicated
{

};

ostream& operator<<(ostream& out, const Complicated&)
{
	out << "Complicated";
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


void processCommand(UserCommand&)
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
			processCommand(cmd);
		}
		catch (const exception& e)
		{
			log("exception from proecessCommand", e.what());

		}
	}
}

int main(int argc, char* argv[])
{
	for (int i = 1; i < argc; i++)
	{
		log(argv[i]);
	}

	Complicated obj;
	trickyFunction(&obj);

	cout << debugBuf;

	return 0;
}



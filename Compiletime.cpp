#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
/*
#define DEBUG_MODE

#ifdef DEBUG_MODE
class Logger
{
public:
	template<typename... Args>
	static void log(const Args&... args)
	{
		ofstream logfile(msDebugFileName, ios_base::app);
		if (logfile.fail()) {
			cerr << "Unable to open debug file!" << endl;
			return;
		}
		// C++17 ���� ���� ���带 �����Ѵ�. (22�� ����)
		((logfile << args), ...);
		logfile << endl;
	}

private:
	static const string msDebugFileName;
};
const string Logger::msDebugFileName = "debugfile.out";

#define log(...) Logger::log(__func__, "(): ", __VA_ARGS__)
#else
#define log(...)
#endif

// ����:
//		���α׷��� ���� ���ۿ� ���õ� �ڵ带 log() ȣ�� �ȿ� ���� �ʵ��� �����Ѵ�.
//      ���� ��� ������ ���� �ۼ��ϸ� ������ �߻��� �� �ִ�.
//		    log("Result: ", myFunctionCall());
//		DEBUG_MODE�� ���ǵǾ� ���� ������ ��ó����� �ڵ忡 ���� ��� log() ȣ�⹮�� no-op���� �ٲ۴�.
//      �׷��� myFunctionCall()�� ȣ���ϴ� ���嵵 �Բ� ���ŵȴ�.

class ComplicatedClass
{
	// �ڵ� ����
};
ostream& operator<<(ostream& ostr, const ComplicatedClass& )
{
	ostr << "ComplicatedClass";
	return ostr;
}

class UserCommand
{
	// �ڵ� ����
};
ostream& operator<<(ostream& ostr, const UserCommand&)
{
	ostr << "UserCommand";
	return ostr;
}



UserCommand getNextCommand(ComplicatedClass* )
{
	UserCommand cmd;
	return cmd;
}

void processUserCommand(UserCommand& )
{
	// �ڵ� ����
}

void trickyFunction(ComplicatedClass* obj)
{
	log("given argument: ", *obj);

	for (size_t i = 0; i < 100; ++i) {
		UserCommand cmd = getNextCommand(obj);
		log("retrieved cmd ", i, ": ", cmd);

		try {
			processUserCommand(cmd);
		}
		catch (const exception& e) {
			log("received exception from processUserCommand(): ", e.what());
		}
	}
}

int main(int argc, char* argv[])
{
#ifdef DEBUG_MODE
	// Ʈ���̽��� ���� Ŀ�ǵ���� �μ��� ����Ѵ�.
	for (int i = 0; i < argc; i++) {
		log(argv[i]);
	}
#endif

	ComplicatedClass obj;
	trickyFunction(&obj);

	// ������ �ڵ� ����
	return 0;
}
*/
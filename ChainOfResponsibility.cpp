#include <iostream>
using namespace std;



class Handler
{
public:
	virtual ~Handler() = default;
	Handler(Handler* nextHandler) : mNextHandler(nextHandler) {}

	virtual void handleMessage(int message)
	{
		if (mNextHandler)
			mNextHandler->handleMessage(message);
	}


private:
	Handler* mNextHandler;
};

// 정교한 핸들러 2개 구현

class ConcreteHandler1 : public Handler
{
public:
	ConcreteHandler1(Handler* nextHandler) : Handler(nextHandler) {}
	void handleMessage(int message) override
	{
		cout << "핸들러1::handleMessage()" << endl;
		if (message == 1)
			cout << "핸들링 메시지 " << message << endl;
		else
		{
			cout << "핸들링 메시지가 아닙니다 " << message << endl;
			Handler::handleMessage(message);
		}
	}

};


class ConcreteHandler2 : public Handler
{
public:
	ConcreteHandler2(Handler* nextHandler) : Handler(nextHandler) {}
	void handleMessage(int message) override
	{
		cout << "핸들러2::handleMessage()" << endl;
		if (message == 2)
			cout << "핸들링 메시지 " << message << endl;
		else
		{
			cout << "핸들링 메시지가 아닙니다 " << message << endl;
			Handler::handleMessage(message);
		}
	}

};


int main()
{

	ConcreteHandler2 handler2(nullptr);
	//초기화

	ConcreteHandler1 handler1(&handler2);

	handler1.handleMessage(1);
	cout << endl;

	handler1.handleMessage(2);
	cout << endl;

	handler1.handleMessage(3);
	cout << endl;



}
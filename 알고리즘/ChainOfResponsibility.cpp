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

// ������ �ڵ鷯 2�� ����

class ConcreteHandler1 : public Handler
{
public:
	ConcreteHandler1(Handler* nextHandler) : Handler(nextHandler) {}
	void handleMessage(int message) override
	{
		cout << "�ڵ鷯1::handleMessage()" << endl;
		if (message == 1)
			cout << "�ڵ鸵 �޽��� " << message << endl;
		else
		{
			cout << "�ڵ鸵 �޽����� �ƴմϴ� " << message << endl;
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
		cout << "�ڵ鷯2::handleMessage()" << endl;
		if (message == 2)
			cout << "�ڵ鸵 �޽��� " << message << endl;
		else
		{
			cout << "�ڵ鸵 �޽����� �ƴմϴ� " << message << endl;
			Handler::handleMessage(message);
		}
	}

};


int main()
{

	ConcreteHandler2 handler2(nullptr);
	//�ʱ�ȭ

	ConcreteHandler1 handler1(&handler2);

	handler1.handleMessage(1);
	cout << endl;

	handler1.handleMessage(2);
	cout << endl;

	handler1.handleMessage(3);
	cout << endl;



}
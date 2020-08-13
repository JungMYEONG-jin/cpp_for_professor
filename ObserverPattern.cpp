#include <iostream>
#include <vector>



using namespace std;


class Observer
{
public:
	virtual ~Observer() = default;

	virtual void notify() = 0;
};


class ConcreteObserver1 : public Observer
{
public:
	void notify() override
	{
		cout << "ConcreteObserver1::notify()" << endl;
	}
};

class ConcreteObserver2 : public Observer
{
public:
	void notify() override
	{
		cout << "ConcreteObserver2::notify()" << endl;
	}
};


class Observable
{
public:
	virtual ~Observable() = default;


	void addObserver(Observer* obs)
	{
		res.push_back(obs);
	}
	void removeObserver(Observer* obs)
	{
		res.erase(remove(begin(res), end(res), obs), end(res));
	}

protected:
	void notifyAll()
	{
		for (auto* obs : res)
			obs->notify();
	}


private:
	vector<Observer*> res;
};


class ObservableSubject : public Observable
{
public:

	void modifyData()
	{
		//...
		notifyAll();
	}
};

int main()
{
	ObservableSubject subject;

	ConcreteObserver1 obs1;

	subject.addObserver(&obs1);

	subject.modifyData();
	cout << endl;

	ConcreteObserver2 obs2;
	subject.addObserver(&obs2);
	subject.modifyData();

	cout << endl;

	subject.removeObserver(&obs1);
	subject.modifyData();
	cout << endl;

}
#include "Pool.h"
#include <iostream>
#include <cstddef>


using namespace std;



class ExpensiveObj
{
public:
	ExpensiveObj() {
		mID = ++msCount; cout << "Constructor " << mID << endl;

	}
	virtual ~ExpensiveObj() { cout << "dtor" << mID << endl; }


private:
	int mID;
	static int msCount;





};

int ExpensiveObj::msCount = 0;


ObjectPool<ExpensiveObj>::Object getExpensiveObject(ObjectPool<ExpensiveObj>& pool)
{
	auto object = pool.acquireObject();

	return object;
}


void processExpensiveObject(ObjectPool < ExpensiveObj>::Object& )
	{

}




/*
int main()
{
	ObjectPool<ExpensiveObj> requestPool;


	{
		vector<ObjectPool<ExpensiveObj>::Object> objects;
		for (size_t i = 0; i < 10; i++) {
			objects.push_back(getExpensiveObject(requestPool));
		}
	}


		cout << "Loop Stats" << endl;
		for (size_t i = 0; i < 100; i++) {
			auto reg = getExpensiveObject(requestPool);
			processExpensiveObject(reg);
		}
		cout << "Loop Finished" << endl;

		return 0;
	
}
*/
#include <cstdlib>
#include <iostream>

using namespace std;

void memoryLeak()
{
	int* p = new int[1000];
	return;
}

void mismatchedFree()
{
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = new int;
	int* p3 = new int[1000];

	delete p1;
	delete[] p2;
	free(p3);
}


void doubleFree()
{
	int* p1 = new int[1000];
	delete[] p1;
	int* p2 = new int[1000];
	delete[] p1;
}

void freeUnallocated()
{
	int* p = reinterpret_cast<int*>(10000);
	delete p;
}

void freeStack()
{
	int x;
	int* p = &x;
	delete p;
}

void accessInvalid()
{
	int* p1 = reinterpret_cast<int*>(1000);
	*p1 = 5;
}

void accessFreed()
{
	int* p1 = new int;
	delete p1;
	int* p2 = new int;
	*p1 = 5;
}

void accessElseWhere()
{
	int x, y[10], z;
	x = 0;
	z = 0;
	for (int i = 0; i <= 10; i++)
	{
		y[i] = 6;
	}
}


void readUninit()
{
	int* p;
	cout << *p << endl;
}






int main(int argc, char* argv[])
{
	try
	{
		readUninit();
	}
	catch (...)
	{
		cout << "error!!!" << endl;
	}
	return 0;
}
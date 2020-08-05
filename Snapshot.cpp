#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


class Process
{
private:
	string name;
	int pid;
	string status;
	string id;
	int mem;
	int com_bit;

public:
	Process() = default;
	Process(string mname, int mpid, string mstatus, string mid, int mmem,int  mcom_bit)
		:name(mname), pid(mpid), status(mstatus), id(mid), mem(mmem), com_bit(mcom_bit)
	{}

	~Process() = default;


	friend ostream& operator<<(ostream& os, Process const& p)
	{
		os << p.name << string(5, ' ') << p.pid << string(5, ' ') << p.status << string(5, ' ') << p.id << string(5, ' ') << p.mem << string(5, ' ') << p.com_bit << "-bit";
		return os;
	}


	string get_name()
	{
		return name;
	}

	int get_mem()
	{
		return mem;
	}
	string get_id()
	{
		return id;
	}

};


bool greater_process(Process& p, Process& k)
{
	if (p.get_name().compare(k.get_name()) <= 0)
	{
		if (p.get_name().compare(k.get_name()) <= 0)
		{
			if (p.get_mem() < k.get_mem())
				return true;
			return false;
		}
		return false;
	}
	return false;

}

void show_process(vector<Process>& test)
{

	sort(test.begin(), test.end(), greater_process);

	for (auto const& p : test)
		cout << p << endl;




}



enum class procstatus{suspended, running};
enum class procbit{p32bit, p64bit};


struct procinfo
{
	string name;
	int pid;
	procstatus status;
	string id;
	size_t mem;
	procbit pbit;
};

string stat_to_string(procstatus const p)
{
	if (p == procstatus::suspended)
		return "suspended";
	else if (p == procstatus::running)
		return "running";
	else
		return "error";
}

string bit_to_string(procbit const p)
{
	if (p == procbit::p32bit)
		return "32-bit";
	else if (p == procbit::p64bit)
		return "64-bit";
	else
		return "error";
}

void print_proc_sort(vector<procinfo> test)
{
	sort(begin(test), end(test), [](procinfo& p1, procinfo& p2) {return p1.name < p2.name; });

	for (auto const& p1 : test)
	{
		cout << left << setw(25) << setfill(' ') << p1.name;
		cout << left << setw(8) << setfill(' ') << p1.pid;
		cout << left << setw(12) << setfill(' ') << stat_to_string(p1.status);
		cout << left << setw(15) << setfill(' ') << p1.id;
		cout << left << setw(10) << setfill(' ') << (int)(p1.mem/1024);
		cout << left <<' '<< bit_to_string(p1.pbit) << endl;

	}



}
















int main()
{
	using namespace string_literals;
	Process a{ "chrome",1044,"Running","mj",25180,32 };
	Process b{ "chrome",10440,"Running","mj",2518011,32 };
	Process c{ "cmd",512,"Running","SYSTEM",48,64 };
	Process d{ "explorer",7108,"Running","mj",29529,64 };






	vector<Process> test{ d,c,b,a };
	vector<procinfo> test2{
		{ "cmd",512,procstatus::running,"SYSTEM",148293,procbit::p64bit },
		{ "chrome",1044,procstatus::running,"mj",25180454, procbit::p32bit },
		{ "explorer",7108,procstatus::running,"mj",2952943, procbit::p32bit },
		{ "chrome",10100,procstatus::running,"mj",227756123, procbit::p64bit },
		{ "skype",22456,procstatus::suspended,"mj",16870123, procbit::p64bit }

	};
	print_proc_sort(test2);




}
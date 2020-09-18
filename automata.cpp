#include <random>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <numeric>
#include <map>
#include <numeric>
#include <limits>
#include <unordered_map>

using namespace std;

map<string, map<string, string>> tcp{
	{"CLOSED",{{"APP_PASSIVE_OPEN","LISTEN"},   {"APP_ACTIVE_OPEN","SYN_SENT"}            }},
	{"LISTEN",{{"RCV_SYN","SYN_RCVD"},   {"APP_SEND","SYN_SENT"} , {"APP_CLOSE","CLOSED"}            }},
	{"SYN_RCVD",{{"APP_CLOSE","FIN_WAIT_1"},   {"RCV_ACK","ESTABLISHED"} , }},
	{"SYN_SENT",{{"RCV_SYN","SYN_RCVD"},   {"RCV_SYN_ACK","ESTABLISHED"} ,{"APP_CLOSE","CLOSED" } }},
	{"ESTABLISHED",{{"APP_CLOSE","FIN_WAIT_1"},   {"RCV_FIN","CLOSE_WAIT"} }},
	{"FIN_WAIT_1",{{"RCV_FIN","CLOSING"},   {"RCV_FIN_ACK","TIME_WAIT"},{"RCV_ACK","FIN_WAIT_2" } }},
	{"FIN_WAIT_2",{{"RCV_FIN","TIME_WAIT"} }},
	{"CLOSING",{{"RCV_ACK","TIME_WAIT"} }},
	{"TIME_WAIT",{{"APP_TIMEOUT","CLOSED"} }},
	{"CLOSE_WAIT",{{"APP_CLOSE","LAST_ACK"} }},
	{"LAST_ACK",{{"RCV_ACK","CLOSED"} }}
};




std::string traverse_TCP_states(const std::vector<std::string>& events) {
	
	string state = "CLOSED";
	string res = "";
	for (auto& i : events)
	{
		if (state == "CLOSED" && i == "APP_PASSIVE_OPEN")
			state = "LISTEN";
		else if (state == "CLOSED" && i == "APP_ACTIVE_OPEN")
			state = "SYN_SENT";
		else if (state == "LISTEN" && i == "RCV_SYN")
			state = "SYN_RCVD";
		else if (state == "LISTEN" && i == "APP_SEND")
			state = "SYN_SENT";
		else if (state == "LISTEN" && i == "APP_CLOSE")
			state = "CLOSED";
		else if (state == "SYN_RCVD" && i == "APP_CLOSE")
			state = "FIN_WAIT_1";
		else if (state == "SYN_RCVD" && i == "RCV_ACK")
			state = "ESTABLISHED";
		else if (state == "SYN_SENT" && i == "RCV_SYN")
			state = "SYN_RCVD";
		else if (state == "SYN_SENT" && i == "RCV_SYN_ACK")
			state = "ESTABLISHED";
		else if (state == "SYN_SENT" && i == "APP_CLOSE")
			state = "CLOSED";
		else if (state == "ESTABLISHED" && i == "APP_CLOSE")
			state = "FIN_WAIT_1";
		else if (state == "ESTABLISHED" && i == "RCV_FIN")
			state = "CLOSE_WAIT";
		else if (state == "FIN_WAIT_1" && i == "RCV_FIN")
			state = "CLOSING";
		else if (state == "FIN_WAIT_1" && i == "RCV_FIN_ACK")
			state = "TIME_WAIT";
		else if (state == "FIN_WAIT_1" && i == "RCV_ACK")
			state = "FIN_WAIT_2";
		else if (state == "CLOSING" && i == "RCV_ACK")
			state = "TIME_WAIT";
		else if (state == "FIN_WAIT_2" && i == "RCV_FIN")
			state = "TIME_WAIT";
		else if (state == "TIME_WAIT" && i == "APP_TIMEOUT")
			state = "CLOSED";
		else if (state == "CLOSE_WAIT" && i == "APP_CLOSE")
			state = "LAST_ACK";
		else if (state == "LAST_ACK" && i == "RCV_ACK")
			state = "CLOSED";
		else
			return "ERROR";

	}

	return state;


	
}


std::string traverse_TCP(const std::vector<std::string>& events) {

	string state = "CLOSED";
	

	for (auto& i : events)
	{
		if (tcp[state].find(i) == tcp[state].end())
			return "ERROR";
		else
			state = tcp[state][i];
			
	}

	return state;



}

int main()
{
	{
		vector<string> test{ "APP_ACTIVE_OPEN","RCV_SYN_ACK","RCV_FIN" };
		cout << traverse_TCP_states(test) << endl;
	}
	{
		vector<string> test{ "APP_PASSIVE_OPEN",  "RCV_SYN","RCV_ACK" };
		cout << traverse_TCP_states(test) << endl;
	}
	{
		vector<string> test{ "APP_ACTIVE_OPEN","RCV_SYN_ACK","RCV_FIN","APP_CLOSE" };
		cout << traverse_TCP_states(test) << endl;
	}
	{
		vector<string> test{ "APP_ACTIVE_OPEN" };
		cout << traverse_TCP_states(test) << endl;
	}
	{
		vector<string> test{ "APP_PASSIVE_OPEN","RCV_SYN","RCV_ACK","APP_CLOSE","APP_SEND" };
		cout << traverse_TCP_states(test) << endl;
	}
	{
		vector<string> test{ "APP_ACTIVE_OPEN","RCV_SYN_ACK","RCV_FIN" };
		cout << traverse_TCP(test) << endl;
	}
	{
		vector<string> test{ "APP_PASSIVE_OPEN",  "RCV_SYN","RCV_ACK" };
		cout << traverse_TCP(test) << endl;
	}
	{
		vector<string> test{ "APP_ACTIVE_OPEN","RCV_SYN_ACK","RCV_FIN","APP_CLOSE" };
		cout << traverse_TCP(test) << endl;
	}
	{
		vector<string> test{ "APP_ACTIVE_OPEN" };
		cout << traverse_TCP(test) << endl;
	}
	{
		vector<string> test{ "APP_PASSIVE_OPEN","RCV_SYN","RCV_ACK","APP_CLOSE","APP_SEND" };
		cout << traverse_TCP(test) << endl;
	}
}
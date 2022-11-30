#include <string>
#include <string_view>
#include <iostream>
#include <array>

#define ASIO_STANDALONE
#include "asio.hpp";

using namespace std;

void run_client(string_view host, short const port)
{
	try {
		asio::io_context context;
		asio::ip::tcp::socket tcp_socket(context);
		asio::ip::tcp::resolver resolver(context);
		asio::connect(tcp_socket, resolver.resolve({ host.data(), to_string(port) }));

		while (true)
		{
			cout << "number [1-99]: ";
			int number;
			cin >> number;
			if (cin.fail() || number < 1 || number>99)
				break;

			auto request = to_string(number);
			tcp_socket.write_some(asio::buffer(request, request.length()));


			array<char, 1024> reply;
			auto reply_length = tcp_socket.read_some(asio::buffer(reply, reply.size()));

			cout << "reply is: ";
			cout.write(reply.data(), reply_length);
			cout << endl;



		}
	}
	catch (exception const& e)
	{
		cerr << "exception: " << e.what() << endl;
	}
}


int main()
{

	run_client("localhost", 11234);




}

#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <array>

#define ASIO_STANDALONE
#include "asio.hpp"

using namespace std;

std::vector<std::string> get_ip_address(std::string_view hostname)
{
   std::vector<std::string> ips;
   try
   {
       asio::io_context context;
       asio::ip::tcp::resolver resolve(context);
       auto end_point = resolve.resolve(asio::ip::tcp::v4(), hostname.data(), "");

       for (auto e = end_point.begin(); e != end_point.end(); e++)
           ips.push_back(((asio::ip::tcp::endpoint) * e).address().to_string());
   }
   catch (std::exception const& ex)
   {
       std::cerr << "Exception: " << ex.what() << std::endl;
   }


   return ips;
}


string fizzbuzz(int  const num)
{
    if (num != 0)
    {
        auto m3 = num % 3;
        auto m5 = num % 5;

        if (m3 == 0 && m5 == 0)
            return "fizzbuzz";
        else if (m3 == 0)
            return "fizz";
        else if (m5 == 0)
            return "buzz";
 
    }
    return to_string(num);
}


class session : public enable_shared_from_this<session>
{
public:
    session(asio::ip::tcp::socket socket)
        :tcp_socket(move(socket))
    {

    }

    void start()
    {
        read();
    }



private:

    void read()
    {
        auto self(shared_from_this());

        tcp_socket.async_read_some(
            asio::buffer(data, data.size()),
            [this, self](error_code const ec, size_t const length) {
                if (!ec)
                {
                    auto number = string(data.data(), length);
                    auto result = fizzbuzz(atoi(number.c_str()));
                    cout << number << " -> " << result << endl;
                    write(result);
                }
            }
        );
    }

    void write(string_view res)
    {
        auto self(shared_from_this());
        tcp_socket.async_write_some(
            asio::buffer(res.data(), res.length()),
            [this, self](error_code const ec, size_t const) {
                if (!ec)
                    read();
            }
        );
    }



    array<char, 1024> data;
    asio::ip::tcp::socket tcp_socket;
};

class server
{
public:
    server(asio::io_context& context, short const port)
        :tcp_acceptor(context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))
        , tcp_socket(context)
    {
        cout << "server running on port " << port << endl;
        accept();
    }


private:

    void accept()
    {
        tcp_acceptor.async_accept(tcp_socket, [this](error_code ec) {
            if (!ec)
                make_shared<session>(move(tcp_socket))->start();

            accept();
            });
    }


    asio::ip::tcp::acceptor tcp_acceptor;
    asio::ip::tcp::socket tcp_socket;


};


void run_server(short const port) {
    try {
        asio::io_context context;
        server srv(context, port);

        context.run();
    }
    catch (exception const& e)
    {
        cerr << "exception: " << e.what() << endl;
    }
}


















int main()
{
   auto ips = get_ip_address("codewars.com");

   for (auto const & ip : ips)
      std::cout << ip << std::endl;

   //run_server(11234);
}

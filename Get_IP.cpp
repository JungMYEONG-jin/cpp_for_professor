// Asio 라이브러리를 이용한 ip주소 획득

#include <string>
#include <string_view>
#include <vector>
#include <iostream>

#define ASIO_STANDALONE

#include "asio.hpp"




using namespace std;

vector<string> get_ip(string_view hostname)
{
vector<string> ip;


try
{
asio::io_context context;
asio::ip::tcp::resolver resolve(conext);
auto end_point = resolve.resolve(asio::ip::tcp::v4(), hostname.data(), "");
for(auto e = end_point.begin(); e!=end_point.end();e++)
{
ip.push_back( ((asio::ip::tcp::endpoint)*e).address().to_string());

}


}catch(exception const& ex)
{


cerr<<"Exception: "<<ex.what()<<endl;

}
return ip;


}


int main()
{
   auto ips = get_ip_address("codewars.com");

   for (auto const & ip : ips)
      std::cout << ip << std::endl;
}

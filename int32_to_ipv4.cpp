#include <stack>
#include <iostream>
#include <string>

using namespace std;


string int_to_ipv4(uint32_t ip)
{
    return to_string((ip >> 24 & 0xFF)) + '.' +
        to_string((ip >> 16 & 0xFF)) + '.' +
        to_string((ip >> 8 & 0xFF)) + '.' +
        to_string((ip & 0xFF));
}

int main()
{

    cout << int_to_ipv4(2154959208);



}
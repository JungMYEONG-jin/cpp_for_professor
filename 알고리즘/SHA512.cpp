#include <iostream>
#include <string>
#include <string_view>
#include <iomanip>
#include <vector>

#include "sha.h"
#include "hex.h"
using namespace std;

struct user
{
	int id;
	string username;
	string password;
	string firstname;
	string lastname;
};

string get_hash(string_view password)
{
	CryptoPP::SHA512 sha;
	CryptoPP::byte digest[CryptoPP::SHA512::DIGESTSIZE];

	sha.CalculateDigest(
		digest, reinterpret_cast<CryptoPP::byte const*>(password.data()), password.length());


	CryptoPP::HexEncoder encoder;
	string res;
	encoder.Attach(new CryptoPP::StringSink(res));
	encoder.Put(digest, sizeof(digest));
	encoder.MessageEnd();
	return res;

}

int main()
{
	std::vector<user> users
	{
	   {
		  101, "scarface",
		  "07A8D53ADAB635ADDF39BAEACFB799FD7C5BFDEE365F3AA721B7E25B54A4E87D419ADDEA34BC3073BAC472DCF4657E50C0F6781DDD8FE883653D10F7930E78FF",
		  "Tony", "Montana"
	   },
	   {
		  202, "neo",
		  "844D8779103B94C18F4AA4CC0C3B4474058580A991FBA85D3CA698A0BC9E52C5940FEB7A65A3A290E17E6B23EE943ECC4F73E7490327245B4FE5D5EF",
		  "Thomas", "Anderson"
	   },
	   {
		  303, "godfather",
		  "0EA7A0306FE00CD22DF1B835796EC32ACC702208E0B052B15F9393BCCF5EE9ECD8BAAF27840D4D3E6BCC3BB3B009259F6F73CC77480C065DDE67CD9BEA14AA4D",
		  "Vito", "Corleone"
	   }
	};
	


	string username, password;
	cout << "Username: ";
	cin >> username;

	cout << "Password: ";
	cin >> password;

	auto hash = get_hash(password);

	auto pos = find_if(users.begin(), users.end(), [username, hash](user const& u) {return u.username == username && hash == u.password; });


	if (pos != users.end())
		cout << "Login Succesful!" << endl;
	else
		cout << "Invalid Username or Password" << endl;
}

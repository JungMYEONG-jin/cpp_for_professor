#include <string>
#include <bitset>
using namespace std;

std::string encode(std::string text)
{
  
   
    string res = "";
    
    for (auto i : text)
      res += bitset<8>(int(i)).to_string();
    string fin;

    for (auto i : res)
      fin += string(3, i);
    return fin;
}

std::string decode(std::string bits)
{
   string res = "";
  for (int i = 0; i <= bits.size() - 3; i += 3)
  {
    string k = bits.substr(i, 3);
    int n0 = count(k.begin(), k.end(), '0');
    int n1 = count(k.begin(), k.end(), '1');
    res += n0 > n1 ? string(1, '0') : string(1, '1');
  }
  

  string temp;

  for (int i = 0; i <= res.size() - 8; i += 8)
    temp += string(1, char(bitset<8>(res.substr(i, 8)).to_ulong()));
  //cout << temp << endl;

  return temp;
}

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <regex>

using namespace std;

typedef long long ll;

void createMap2(unordered_map<char, string>* m)
{
    (*m)['0'] = "000";
    (*m)['1'] = "001";
    (*m)['2'] = "010";
    (*m)['3'] = "011";
    (*m)['4'] = "100";
    (*m)['5'] = "101";
    (*m)['6'] = "110";
    (*m)['7'] = "111";
}

string Octal_to_Bin(string oct)
{
    unordered_map<char, string> oct_bin;
    createMap2(&oct_bin);

    string bin;
    int i = 0;
    while (true)
    {
        bin += oct_bin[oct[i]];
        i++;
        if (i == oct.size())
            break;
    }

    bin = regex_replace(bin, regex("^0+"), "");

    return bin;
}


int main() {

    string k;
    cin >> k;
    if(k=="0")
    {
        cout<<"0"<<endl;
        return 0;
    }
    cout << Octal_to_Bin(k) << endl;
    return 0;

}






#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;




class Rank
{
public:
    static std::string nthRank(const std::string& st, std::vector<int>& we, int n);
};


string Rank::nthRank(const std::string& st, std::vector<int>& we, int n)
{

    if (st.empty())
        return "No participants";


    map<char, int> alphabet;
    int i = 1;
    for (char ch = 'a'; ch <= 'z'; ch++)
        alphabet[ch] = i++;

    string temp;
    vector<string> name;
    stringstream sr(st);

    while (getline(sr, temp, ','))
        name.push_back(temp);

    if (n > name.size())
        return "Not enough participants";


    vector<pair<string, int>> test;
    int p = 0;
    int total = 0;
    for (auto it : name)
    {
        for (auto k : it)
        {
            total += alphabet[tolower(k)];
        }

        test.push_back(make_pair(it, (it.size() + total) * we[p]));
        total = 0;
        p++;
    }


    sort(test.begin(), test.end(), [](auto const& k, auto const& p) {
        return k.second > p.second || (k.second >= p.second && k.first < p.first);
        });

    return test[n - 1].first;

}

int main()
{
    string st = "COLIN,AMANDBA,AMANDAB,CAROL,PauL,JOSEPH";
    std::vector<int> we = { 1, 4, 4, 5, 2, 1 };

    cout << Rank::nthRank(st, we, 4);

}
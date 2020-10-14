#include <map>
#include <string>
#include <iostream>
using namespace std;

std::string vowelShift(std::string text, int n)
{
    if (n == 0)
        return text;

    map<int, char> res;

    string vowel = "aeiouAEIOU";
    long long total = 0;
    for (auto i : text)
    {
        if (vowel.find(i) != vowel.npos)
        {
            total++;
            res[total - 1] = i;
        }

    }

    // total¿∫ ¿¸√º

    map<int, char> res2;
    int k = n;
    if (n < 0)
    {
        k = total + n;
        if (k < 0)
        {
            while (k < 0)
                k += total;
        }
    }



    for (auto it : res)
    {

        res2[(it.first + (k)) % total] = it.second;
    }

    for (auto it : res2)
        cout << it.first << " " << it.second << " " << k << endl;


    auto it = res2.begin();
    for (int i = 0; i < text.size(); i++)
    {
        if (vowel.find(text[i]) != vowel.npos)
        {
            text[i] = it->second;
            it++;
        }
    }







    return text;
}
#include <string>
#include <map>
#include <iostream>
using namespace std;

string rot13(string msg)
{
    if (msg.empty())
        return "";

    map<char, int> res;
    int i = 1;
    for (char ch = 'a'; ch <= 'z'; ch++)
        res[ch] = i++;


    map<int, char> res2;
    int k = 1;
    for (char ch = 'a'; ch <= 'z'; ch++)
        res2[k++] = ch;


    k = 50;
    for (char ch = 'A'; ch <= 'Z'; ch++)
        res2[k++] = ch;


    i = 50;
    for (char ch = 'A'; ch <= 'Z'; ch++)
        res[ch] = i++;
    string temp;
    for (auto j : msg)
    {
        if (res[j] >= 1 && res[j] <= 13)
            temp += res2[res[j] + 13];
        else if (res[j] >= 14 && res[j] <= 26)
            temp += res2[res[j] - 13];
        else if (res[j] >= 50 && res[j] <= 62)
            temp += res2[res[j] + 13];
        else if (res[j] >= 63 && res[j] <= 75)
            temp += res2[res[j] - 13];
        else
            temp += j;
    }


    return temp;

}

//BEST CODE
string Rot13_best(string text)
{
    string res = "";
    for (auto& i : text)
    {
        if (isalpha(i))
        {
            if (islower(i))
                res += 'a' + (i - 'a' + 13) % 26;
            else if (isupper(i))
                res += 'A' + (i - 'A' + 13) % 26;
        }
        else
            res += i;
    }
    return res;
}

int main()
{
    cout << rot13("test") << endl;
    cout << rot13("Test") << endl;
    cout << rot13("AbCd") << endl;
    cout << Rot13_best("test") << endl;
    cout << Rot13_best("Test") << endl;
    cout << Rot13_best("AbCd") << endl;
}
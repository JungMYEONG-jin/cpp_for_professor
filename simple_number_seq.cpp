#include <iostream>
#include <string>
using namespace std;

int missing(std::string s) {
    bool finded = false;
    int findNum;
    for (int i = 1; (i <= s.size() / 2) && i < 7; i++)
    {
        int currNum = stoi(s.substr(0, i));

        for (int idx = i; idx < s.size();)
        {
            string curr1 = to_string(currNum + 1);
            string curr2 = to_string(currNum + 2);


            if (currNum + 1 == stoi(s.substr(idx, curr1.size())))
            {
                ++currNum;
                idx += curr1.size();
            }
            else if (currNum + 2 == stoi(s.substr(idx, curr2.size())))
            {
                if (!finded)
                {
                    finded = true;
                    findNum = currNum + 1;
                    currNum += 2;
                    idx += curr2.size();
                }
                else
                {
                    finded = false;
                    break;
                }
            }
            else
            {
                finded = false;
                break;
            }

        }
        if (finded) return findNum;
    }
    return -1;
}


int main()
{
    cout << missing("123567") << endl;
    cout << missing("899091939495") << endl;
    cout << missing("9899101102") << endl;
    cout << missing("599600601602") << endl;
    cout << missing("8990919395") << endl;
    cout << missing("998999100010011003") << endl;
    cout << missing("99991000110002") << endl;
    cout << missing("979899100101102") << endl;
    cout << missing("900001900002900004900005900006") << endl;
}
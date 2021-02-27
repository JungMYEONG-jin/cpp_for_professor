#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <regex>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <sstream>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.tie(NULL);
    int t;
    cin >> t;
    int n;
    string str;
    string result;

    string command;
    for (int i = 0; i < t; i++) {
        cin >> command;
        cin >> n;
        cin >> str;


        deque<int> res;


        string temp = "";
        for (int i = 0, lens = str.size(); i < lens; i++)
        {
            if (isdigit(str[i]))
                temp += str[i];
            else
            {
                if (!temp.empty())
                    res.push_back(stoi(temp));
                temp = "";
            }

        }


        bool err=false;
        int rev_num = 0;


        for (auto& i : command)
        {
            if (i == 'R')
                rev_num++;
            else if (i == 'D')
            {

                if (res.empty())
                {
                   err = true;
                    break;
                }
                else
                {

                    if (rev_num % 2 == 0)
                        res.pop_front();
                    else
                        res.pop_back();

                }
            }
        }

        if(err)
            cout<<"error\n";
        else if (res.empty())
            cout << "[]\n";
        else if (rev_num % 2 != 0) // reverse
        {
            cout << '[';
            int len = res.size();
            for (int i = len - 1; i > 0; i--)
            {

                cout << res[i] << ',';

            }
            cout << res.front() << "]\n";
        }
        else if (rev_num % 2 == 0) {

            cout << '[';
            int len = res.size();
            for (int i = 0; i < len - 1; i++)
            {

                cout << res[i] << ',';

            }
            cout << res.back() << "]\n";
        }

    }

}

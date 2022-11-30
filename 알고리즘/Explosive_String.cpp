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

using namespace std;




int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.tie(NULL);
    string str;
    string bomb;

    cin >> str;
    cin >> bomb;
    int len = bomb.size();
    string temp;
    bool flag = true;

    for (auto c : str)
    {
        flag = true;
        temp += c;

        if (temp.size() < len || c != temp.back()) continue;

        // 만약 끝문자가 같다면
        for (int i = 0; i < len; i++)
        {
            if (temp[temp.size() - i - 1] != bomb[len - i - 1])
            {
                flag = false;
                break;
            }
        }

        if (flag)
            temp.erase(temp.size() - len);

    }

    if (temp.empty())
        cout << "FRULA\n";
    else
        cout << temp;

}

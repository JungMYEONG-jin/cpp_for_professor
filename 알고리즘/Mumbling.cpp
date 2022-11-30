#include <iostream>
#include <string>
#include <regex>
#include <ostream>
#include <sstream>
#include <vector>
#include <thread>
#include <functional>
#include <algorithm>
#include <random>
#include <array>
#include <list>
#include <map>
#include <unordered_map>


using namespace std;

int solve(std::vector<std::vector<int>> v) {
    //..
    auto res = std::vector<int>{};
    for (int i = 1; i < v.size(); i++)
    {

        std::transform(v[0].begin() + 1, v[0].end(),v[i].begin()+1,
             res.begin(), std::multiplies<int>());

    }
    
    for (auto p : res)
        cout << p << endl;
    return 1;

}

string accum(const std::string& s)
{
   
    int i = 0;
    vector<int> test;
    for (auto& k : s)
    {
        test.push_back(i++);
    }
    int j = 0;
    string t1 = "";
    for (auto& k : s)
    {
        t1 += toupper(k);
        for (int i = 0; i < test[j]; i++)
        {
            t1 += tolower(k);
        }
        t1 += "-";
        j++;
    }

    t1.erase(t1.size() - 1, 1);
    return t1;


    //best code
    stringstream st;
    for (int i = 0; i < s.size(); i++)
    {
        st << "-" << string(1, toupper(s[i])) << string(i, tolower(s[i]));
    }
    return st.str().substr(1);
   

}

int main()
{
    cout << accum("abcd") << endl;// -> "A - Bb - Ccc - Dddd"
    cout << accum("RqaEzty") << endl; //-> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
    cout << accum("cwAt") << endl;
    string a =string(2, 'c');
    cout << a << endl;
}

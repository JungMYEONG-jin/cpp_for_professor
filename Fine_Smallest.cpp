#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;


class ToSmallest
{
public:
    static std::vector<long long> smallest(long long n);
};


vector<long long> ToSmallest::smallest(long long n)
{

    string test = to_string(n);
    vector<vector<long long>> res;
  
    for (int i = 0; i < test.length(); i++)
    {
        for (int j = 0; j < test.length(); j++)
        {
            string tmp = test;
            tmp.erase(i, 1);
            tmp.insert(j, 1, test[i]);

            res.push_back({ stoll(tmp), i,j });
        }
    }
   

    return *min_element(res.begin(), res.end());
    

   
    


}

int main()
{

    auto k =ToSmallest::smallest(261235);
    
    for (auto const& i : k)
        cout << i << ' ';
    cout << endl;


    auto r = ToSmallest::smallest(209917);

    for (auto const& i : r)
        cout << i << ' ';
    cout << endl;

    auto m = ToSmallest::smallest(285365);

    for (auto const& i : m)
        cout << i << ' ';
    cout << endl;

    auto p = ToSmallest::smallest(296837);

    for (auto const& i : p)
        cout << i << ' ';
    cout << endl;


    auto t = ToSmallest::smallest(269045);

    for (auto const& i : t)
        cout << i << ' ';
    cout << endl;
}
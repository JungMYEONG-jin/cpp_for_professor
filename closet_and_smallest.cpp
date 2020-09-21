#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <tuple>
#include <map>

using namespace std;

int get_weight(string str)
{
    int sum = 0;
    for (auto i : str)
        sum += i - '0';
    return sum;
}


std::vector<std::tuple<int, unsigned int, long long>> closest(const std::string& strn)
{




    // your code
    vector<tuple<int, unsigned int, long long>> res;

    stringstream st(strn);
    int i = 0;
    int temp;
    while (st >> temp)
    {

        res.push_back(make_tuple(get_weight(to_string(temp)), i++, temp));
    }


    //sort(res.begin(), res.end(), [](auto e, auto k) {return get<0>(e) < get<0>(k) || get<0>(e) == get<0>(k) && get<1>(e) < get<1>(k); });



    int minw = abs(get<0>(res[0]) - get<0>(res[1]));
    int curw = get<0>(res[1]);
    int curp = 0;
    int nextp = 1;
    for (int i = 0; i < res.size() - 1; i++)
    {
        for (int j = i + 1; j < res.size(); j++)
        {
            if (minw > abs(get<0>(res[i]) - get<0>(res[j])) || minw == abs(get<0>(res[i]) - get<0>(res[j])) && curw > get<0>(res[j]))
            {
                minw = abs(get<0>(res[i]) - get<0>(res[j]));
                curw = get<0>(res[j]);
                curp = i;
                nextp = j;
            }
        }
    }

    std::vector<std::tuple<int, unsigned int, long long>> result;

    result.push_back(make_tuple(get<0>(res[curp]), get<1>(res[curp]), get<2>(res[curp])));
    result.push_back(make_tuple(get<0>(res[nextp]), get<1>(res[nextp]), get<2>(res[nextp])));



    sort(result.begin(), result.end(), [](auto e, auto k) {return get<0>(e) < get<0>(k); });



    return result;
}

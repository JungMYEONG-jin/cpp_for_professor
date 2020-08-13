#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int solve(std::vector <int> v) {
    //..
    int min = 0;
    sort(v.begin(), v.end());
    for (auto const& p : v)
    {
        if (min + 1 < p)
            break;
        else
            min += p;

    }
    // 1을 return 하는 경우임




    return min + 1;


}





int main()
{

    cout << solve(vector<int>{ 1, 2, 8, 7 });// Equals(4));
    cout << endl;
    cout << solve(vector<int>{ 2, 12, 3, 1 });// Equals(7));
    cout << endl;
    cout << solve(vector<int>{ 4, 2, 8, 3, 1 });// Equals(19));
    cout << endl;
    cout << solve(vector<int>{ 4, 2, 12, 3 });// Equals(1));
    cout << endl;
    cout << solve(vector<int>{ 1, 2, 4 });// Equals(8))

}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Same {
public:
    static bool comp(std::vector<int> a, std::vector<int> b)
    {

        if (a.size() != b.size())
            return false;
        if (a.empty())
            return true;

        for (auto& p : a)
        {
            p = p * p;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        return a == b;



    }

};



int main()
{
	std::vector<int> a = { 121, 144, 19, 161, 19, 144, 19, 11 };
	std::vector<int> b = { 14641, 20736, 361, 25921, 361, 20736, 361, 121 };
	



	cout << Same::comp(a, b) << endl;

	a = { 121, 144, 19, 161, 19, 144, 19, 11 };
	b = { 14641, 20736, 361, 25921, 361, 20736, 362, 121 };

	cout << Same::comp(a, b) << endl;
}
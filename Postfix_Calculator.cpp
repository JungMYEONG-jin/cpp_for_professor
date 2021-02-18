#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <regex>
#include <map>
#include <stack>
using namespace std;



double evaluate(string str, map<char, int>& m)
{
    stack<double> res;
    double sum = 0;
    for (auto i : str)
    {
        if (isupper(i))
            res.push(m[i]);
        else// operation
        {

            double a = double(res.top());
            res.pop();
            double b = double(res.top());
            res.pop();

            switch (i)
            {
            case '*':
                sum = b * a;
                break;
            case '/':
                sum = b/a;
                break;
            case '+':
                sum =b+a;
                break;
            case '-':
                sum = b -a;
                break;

            }
            res.push(sum);
        }
    }
    return res.top();
}





int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    string str;
    cin >> str;
    map<char, int> res;
    for (auto i : str)
    {
        if (isupper(i))
            res[i] = 0;
    }
    
    for (auto& i : res)
    {
        cin >> i.second;
    }
    cout << fixed;
    cout.precision(2);
    cout << evaluate(str, res) << endl;

}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
     int num;
    cin >> num;
    vector<int> a;
    for (int i = 0; i < num; i++)
    {
        int j;
        cin >> j;
        a.push_back(j);
    }


    int del;
    cin >> del;

    a.erase(begin(a) + del - 1);
    int one, sec;
    cin >> one >> sec;

    a.erase(begin(a) + one-1, begin(a) + sec-1);

    cout << a.size() << endl;

    for (const auto& i : a)
    {
        cout << i << " ";
    }





    return 0;
}

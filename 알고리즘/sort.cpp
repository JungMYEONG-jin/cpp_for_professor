#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int num;
    cin>>num;

    vector<int> a;
    for(int i=0;i<num;i++)
    {
        int j;
        cin>>j;
        a.push_back(j);
    }
    sort(begin(a), end(a));
    for(const auto& i : a)
    {
        cout<<i<<" ";
    }
    cout<<endl;


    return 0;
}

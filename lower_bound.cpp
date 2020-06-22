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
    for (int i = 0; i < del; i++)
    {
       int j;
       cin>>j;

       auto res=lower_bound(a.begin(), a.end(), j);
       if(a[res-a.begin()]==j)
       {
           cout<<"Yes "<<res-begin(a)+1<<endl;
       }else
       {
           cout<<"No "<<res-begin(a)+1<<endl;
       }
    }







    return 0;
}

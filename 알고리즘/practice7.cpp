#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int num, found;
    cin>>num>>found;
  

    vector<vector<int>> a(num);


    for(int i=0;i<num;i++)
    {
        int k;
        cin>>k;

        a[i].resize(k);
        for(int j=0;j<k;j++)
        {
          cin>>a[i][j];
        }

    }

    for(int i=0;i<found;i++)
    {
        int p,q;
        cin>>p>>q;
        cout<<a[p].at(q)<<endl;
    }






    return 0;
}

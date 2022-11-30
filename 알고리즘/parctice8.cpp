#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    map<string, int> m;
    int num;
    cin>>num;

    for(int i=0;i<num;i++)
    {
       int choice;
       cin>>choice;
        string str;
        int marks;
       switch(choice)
       {
        case 1:
            cin>>str>>marks;
            m[str]+=marks;
            break;
        case 2:
            cin>>str;
            m.erase(str);
            break;
        case 3:
            cin>>str;
            cout<< m[str] <<endl;
            break;

       }

    }



    return 0;
}




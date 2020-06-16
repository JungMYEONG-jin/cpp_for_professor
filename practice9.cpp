#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    vector<int> a;
    stringstream ss(str);
    int b=0;
    char ch;
    while(ss>>b)
    {
        a.push_back(b);
        ss>>ch; // int,int 이런 형식이므로 stream int 처리후 char로 콤마 
    }

    return a;


}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a;
    string b;

    cin>>a>>b;

    cout<<a.size()<<" "<<b.size()<<endl;
    cout<<a+b<<endl;
    swap(a[0], b[0]);
    cout<<a<<" "<<b<<endl;






  
    return 0;
}




문제 조건
첫 라인은 string size
2번째라인 string append
3번째 라인 a,b 첫글자 swap후 표시

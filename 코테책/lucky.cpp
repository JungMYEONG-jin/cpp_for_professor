#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string res = to_string(n);
    int len = res.size();
    string left = res.substr(0, len/2);
    string right = res.substr(len/2);
    
    auto get_sum = [](string e){
      int s = 0;
        for(auto i : e)
            s+=(i-'0');
        return s;
    };
    
    if(get_sum(left)==get_sum(right))
        cout<<"LUCKY\n";
    else
        cout<<"READY\n";
    
    
}

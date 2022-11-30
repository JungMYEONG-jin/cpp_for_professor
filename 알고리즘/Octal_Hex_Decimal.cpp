#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <map>
#include <cmath>

using namespace std;




void createMap(map<char, int>* m)
{
    (*m)['0'] = 0;
    (*m)['1'] = 1;
    (*m)['2'] = 2;
    (*m)['3'] = 3;
    (*m)['4'] = 4;
    (*m)['5'] = 5;
    (*m)['6'] = 6;
    (*m)['7'] = 7;
    (*m)['8'] = 8;
    (*m)['9'] = 9;
    (*m)['a'] = 10;
    (*m)['b'] = 11;
    (*m)['c'] = 12;
    (*m)['d'] = 13;
    (*m)['e'] = 14;
    (*m)['f'] = 15;
   
}


int hex_to_dec(string k)
{
   
    int sum=0;
    map<char, int> res;
    createMap(&res);
    
    for(int i=0, len=k.size();i<len;i++)
    {
        sum+=pow(16, len-i-1)*res[k[i]];
    }
    return sum;
    
    
}


int octal_to_dec(string k)
{
    int dec = 0;
    
    for(int i=0,len=k.size();i<len;i++)
    {
        dec+=pow(8, len-i-1)*(k[i]-'0');
    }
    return dec;
}


int main()
{
    
    
    
    
    string k;
    cin>>k;
    if(k.substr(0,2)=="0x")
    {
        cout<<hex_to_dec(k.substr(2))<<endl;
    }else if(k[0]=='0')
    {
        cout<<octal_to_dec(k.substr(1))<<endl;
    }else
        cout<<k<<endl;
    
    
    
    
    
}









/* Short CODE
#include <cstdio>
int main()
{
    int x;
    scanf("%i", &x);
    printf("%d", x);
    return 0;
}
*/

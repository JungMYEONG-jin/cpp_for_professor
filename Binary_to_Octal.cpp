#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>

using namespace std;

typedef long long ll;

void createMap(unordered_map<string, char>* m)
{
    (*m)["000"] = '0';
    (*m)["001"] = '1';
    (*m)["010"] = '2';
    (*m)["011"] = '3';
    (*m)["100"] = '4';
    (*m)["101"] = '5';
    (*m)["110"] = '6';
    (*m)["111"] = '7';
}

string Bin_to_Octal(string bin)
{
    int i = bin.size();
    
    
    for(int j=1;j<=(3-i%3)%3;j++)
    {
        bin='0'+bin;
    }
    
    
    unordered_map<string, char> bin_oct;
    createMap(&bin_oct);
    
    int k =0;
    string octal="";
    
    while(true)
    {
        octal+=bin_oct[bin.substr(k,3)];
        k+=3;
        
        if(k==bin.size())
            break;
        
        
    }
    return octal;
    
}





int main() {
  
    string k;
    cin>>k;
    cout << Bin_to_Octal(k)<<endl;
    return 0;

}







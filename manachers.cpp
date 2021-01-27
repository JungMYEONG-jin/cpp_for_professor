#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <assert.h>
#include <string>
#include <map>

using namespace std;

const int Max = 100001*2;

string temp, str;

int arr[Max];



// 일반적인 펠린드롬으로는 시간초과뜸
//  manachers 알고리즘 사용

void manachers(string k, int n)
{
    int l=0, h=0;
    
    for(int i=0;i<n;i++)
    {
        if(i<=l)
            arr[i]=min(arr[2*h-i], l-i);
        else
            arr[i]=0;
        
        while(i-arr[i]-1>=0 && i+arr[i]+1<n && k[i-arr[i]-1]==k[i+arr[i]+1])
            arr[i]++;
       
        if(l<i+arr[i])
        {
            l = i+arr[i];
            h=i;
        }
        
        
    
    
    }
}



int main()
{
    cin>>temp;
    int len = temp.size();
    for(int i=0;i<len;i++)
    {
        str+='#';
        str+=temp[i];
    }
    str+='#';
    
    manachers(str, str.size());
    
    len = str.size();
    int res=-1;
    for(int i=0;i<len;i++)
    {
        res = max(res, arr[i]);
    }
    cout<<res<<endl;
}

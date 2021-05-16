# Suffix sort 알고리즘

1. radix sort 기법에 포함됨
2. 2^n 씩 길이를 비교한다.
3. O(nLogn) time complexity를 갖는다.

```c++
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>
#include <cmath>


using namespace std;

void msd_sort(vector<string>& arr, int low, int high, int d)
{
    if(low>=high)
        return;
        
        
    int left = low;
    int right = high;
    int v = arr[low][d];
    int i = low+1;
    
    while(i<=right)
    {
        int t = arr[i][d];
        if(v>t)
            swap(arr[left++], arr[i++]);
        else if(t>v)
            swap(arr[i], arr[right--]);
        else
            i++;
    }
    
    msd_sort(arr, low, left-1, d);
    if(v>=0)
        msd_sort(arr, left, right, d+1);
    msd_sort(arr, right+1, high, d);
    
    
}

void msd_sort(vector<string>& arr)
{
    
    msd_sort(arr, 0, arr.size()-1, 0);
}



typedef struct suffix
{
    int index;
    int rank[2];
}suffix;


int cmp(suffix a, suffix b)
{
    return(a.rank[0]==b.rank[0])?(a.rank[1]<b.rank[1]?1:0):(a.rank[0]<b.rank[0]?1:0);
}

vector<int> buildSuffixArray(string txt)
{
    
    int len = txt.size();
    suffix suffixes[len];
    
    // suffix와 인덱스를 저장
    // 알파벳순으로 정렬한다
    // 정렬하면서 이전 인덱스 유지해야함
    for(int i=0;i<len;i++)
    {
        suffixes[i].index=i;
        suffixes[i].rank[0] = txt[i]-'a';
        suffixes[i].rank[1] = ((i+1)<len)?(txt[i+1]-'a'):-1;
    }
    
    // suffixes 정렬
    sort(suffixes, suffixes+len, cmp);
    
    // 2^n 처럼 비교하자 2 >> 4 >>8 식으로 16
    int ind[len];
    
    for(int k=4;k<2*len;k*=2)
    {
        int rank=0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank; // rank update
        ind[suffixes[0].index]=0;
        
        
        // rank 할당
        for(int i=1;i<len;i++)
        {
            if(suffixes[i].rank[0]==prev_rank && suffixes[i].rank[1] == suffixes[i-1].rank[1])
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }else
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index]=i;
        }
        
        // next rank를 모든 suffix에 할당
        for(int i=0;i<len;i++)
        {
            int nextindex = suffixes[i].index+k/2;
            suffixes[i].rank[1] = (nextindex<len)?suffixes[ind[nextindex]].rank[0]:-1;
            
        }
        sort(suffixes, suffixes+len, cmp);
        
    }
    
    
    // store index of all sorted suffixes
    vector<int> suffixArr(len);
    for(int i=0;i<len;i++)
        suffixArr[i] = suffixes[i].index;
        
    return suffixArr;
    
    
}


int main()
{
   
    string txt = "banana";
    
    auto suffixArr = buildSuffixArray(txt);
    cout << "Following is suffix array for " << txt << endl;
    for(auto i : suffixArr)
        cout<<i<<" ";
    cout<<endl;
	    
	

}


```

## 결과
```
Following is suffix array for banana
5 3 1 0 4 2 

```

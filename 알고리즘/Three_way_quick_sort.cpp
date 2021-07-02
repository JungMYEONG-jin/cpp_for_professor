/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void partition(vector<int>& arr, int low, int high, int& i, int& j)
{
    
     i = low-1; j =high;
     int left = low-1;
     int right = high;
    
    int val = arr[high];
    
    while(true)
    {
        
        while(arr[++i]<val);
        
        while(arr[--j]>val)
            if(j==low)
                break;
                
        if(i>=j)
            break;
            
        swap(arr[i], arr[j]);
        
        if(arr[i]==val)
        {
            swap(arr[i], arr[++left]);
        }
        
        if(arr[j]==val)
        {
            swap(arr[j], arr[--right]);
        }
        
        
        
        
    }
    swap(arr[i], arr[high]);
    
    j = i-1;
    
    for(int k=low;k<left;k++, j--)
        swap(arr[k], arr[j]);
        
    i = i+1;
    
    for(int k=high-1;k>right;k--, i++)
        swap(arr[k], arr[i]);
    
    
}

void quicksort(vector<int>& arr, int low, int high)
{
    
    if(low>=high)
        return;
    int i,j;
    partition(arr, low, high, i, j);
    quicksort(arr, low, j);
    quicksort(arr, i, high);
    
}






int main()
{
    vector<int> arr{10, 7, 8, 9,9,9, 1, 5};

    for(auto i : arr)
        cout<<i<<" ";
    cout<<endl;
    
    quicksort(arr, 0, arr.size()-1);
   for(auto i : arr)
        cout<<i<<" ";
    cout<<endl;
    
    return 0;
}

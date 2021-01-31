#include <cmath>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 50




int main()
{
	int T;
	cin >> T;
	vector<int> res(T);
	
	for (int i = 0; i < T; i++)
	{
		cin >> res[i];
	}
	int arr[1001];
    fill(arr, arr+1001, 1);
    int count=1;
    for(int i=0;i<T;i++)
    {
        int val = res[i];
        for(int j=0;j<i;j++)
        {
            if(val>res[j])
                arr[i] = max(arr[i], arr[j]+1);
        }
        
        count = max(count, arr[i]);
    }
    cout<<count<<endl;


}


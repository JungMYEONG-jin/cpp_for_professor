
// MY CODE
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
    cin>>n;
    int arr[n*n];
    for(int i=0;i<n*n;i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n*n, greater<int>());
    cout<<arr[n-1]<<endl;
    
    
    
}


















/* 

메모리 시간 최대 성능 코드

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
int main()
{
	fastio;
	int n = 0;
	priority_queue<int, vector<int>, greater<int>> pq;//최소 힙
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num = 0;
			cin >> num;
			int sz = pq.size();
			if (sz < n)
				pq.push(num);//메모리 제한 때문에 n개 이상 받으면 안 됨
			else if (num > pq.top())//최소 힙보다 크면
			{
				pq.push(num);
				pq.pop();//최소 빼기
			}
			else continue;
		}
	}
	cout << pq.top() << '\n';//큰 수 중에 N번째 최댓값
	return 0;
}












*/

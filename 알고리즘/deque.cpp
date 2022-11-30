#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> a;
    int findmax=0;
    for(int i=0;i<k;i++) // 일단 첫번째 max 구하기
    {
        a.push_back(arr[i]);
    }
    findmax=*max_element(a.begin(), a.end());
    cout<<findmax<<" ";


    for(int i=k;i<n;i++)
    {
        int ifront=a.front();
        
        a.pop_front();
        a.push_back(arr[i]);

        if(ifront==arr[i]) //아까 제거한게 지금 들어온거랑 같으면 max는 그대로
        {
            cout<<findmax<<" ";
        }
        else //아까 제거한게 max값이면 새로 max 찾아야함, 맥스값이 아닐경우 새로 들어온값과 맥스값 비교해서 교체
        {

            if(ifront==findmax)
            {
                findmax=*max_element(a.begin(), a.end());
                
            }
            else
            {
                if(findmax < arr[i])
                {
                    findmax=arr[i];
                }
            }

            cout<<findmax<<" ";


        }


    }

    cout<<endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

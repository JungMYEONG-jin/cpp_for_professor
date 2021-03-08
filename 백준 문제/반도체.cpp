#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    vector<int> res;
    res.push_back(arr[0]);
    
    
    
    auto bin_search = [](vector<int>& res, int num){
      int left=0;
      int right = res.size()-1;
    	int min_val=9999999;  
      while(left<=right)
      {
          int mid = (left+right)/2;
          
          if(res[mid]<num)
          {
              left = mid+1;
          }else
          {
              min_val = min(min_val ,mid);
              right=mid-1;
          }
      }
        res[min_val] = num;
    };
    
    
    
    
    for(int i=1;i<n;i++)
    {
        if(res.back()<arr[i])
            res.push_back(arr[i]);
        else
            bin_search(res, arr[i]); // find lowe bound 
        // lower_bound(res.begin(), res.end(), arr[i]) or use own lower method
    }
    
    
    
    
    cout<<res.size()<<endl;
    
}

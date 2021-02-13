#include <iostream>
#include <vector>


using namespace std;

vector<int> jose(vector<int> arr, int k)
{
    
    int len = arr.size();
    int i=0;
    vector<int> temp;
    
    while(len>0)
    {
        i = (i+k-1)%len;
        temp.push_back(arr[i]);
        arr.erase(arr.begin()+i);
        len--;
    }
    
    return temp;
}



int main()
{
    vector<int> res;
    
    int n,k;
    cin>>n>>k;
    
    for(int i=1;i<=n;i++)
    {
        
        
        res.push_back(i);
        
        
        
    }
    
    auto result = jose(res, k);
    
    
    if(result.size()==1)
    {
        cout<<"<"<<result[0]<<">";
        return 0;
    }
    
    
    
    for(int i=0, len = result.size();i<len;i++)
    {
        if(i==0)
        {
            cout<<"<"<<result[i]<<", ";
        }else if(i<len-1)
        {
            cout<<result[i]<<", ";
        }else if(i==len-1)
        {
            cout<<result[i]<<">\n";
        }
        
        
    }
    
    return 0;
    
    
    
    
    
    
}

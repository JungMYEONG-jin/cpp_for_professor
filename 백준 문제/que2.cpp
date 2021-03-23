#include <deque>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>


using namespace std;


int main()
{

    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

int n;
cin>>n;

    priority_queue<int> min_heap;
    priority_queue<int, vector<int>, greater<int>> max_heap;
    
    
    
    
    
int x;    
    
    
    
for(int i=0;i<n;i++)
{
cin>>x;
if(min_heap.size()<=max_heap.size())
    min_heap.push(x);
else
    max_heap.push(x);
    
    if(!min_heap.empty() && !max_heap.empty())
    {
        if(min_heap.top()>max_heap.top())
        {
            int minval = max_heap.top();
            int maxval = min_heap.top();
            
            max_heap.pop();
            min_heap.pop();
            
            min_heap.push(minval);
            max_heap.push(maxval);
        }
    }
    
    
    
    
    cout<<min_heap.top()<<'\n';
    
    
}



}

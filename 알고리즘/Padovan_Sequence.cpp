#include <iostream>

using namespace std;


long padovan(int n)
{
   
   long prevprev=1;
    long prev=1;
    long cur=1;
    long next=1;
    
    for(int i=3;i<=n;i++)
    {
        next = prevprev+prev;
        prevprev=prev;
        prev=cur;
        cur=next;
    }
    return next;
}




int main()
{
int N;
cin>>N;
int x;
for(int i=0;i<N;i++)
{
    cin>>x;
    cout<<padovan(x-1)<<endl;
}

}

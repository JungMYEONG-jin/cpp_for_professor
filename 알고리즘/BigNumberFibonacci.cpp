#include <iostream>
#include <vector>

#define MAX 1500051
using namespace std;
long long Fib[MAX];

void Fibo()
{
   //Fib.resize(n);
   Fib[0]=0;
   Fib[1]=1;
   for(long long i=2;i<1500000;i++)
    {
        Fib[i] = (Fib[i-1]+Fib[i-2])%1000000;
    }
}

int main()
{
    long long N;
    cin>>N;
    Fibo();
    cout<<Fib[N%1500000]<<endl;
}

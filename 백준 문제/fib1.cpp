#include <iostream>

using namespace std;

void multiple(long long f[2][2], long long m[2][2])
{

long long x = (f[0][0]*m[0][0]+f[0][1]*m[1][0])%1000000007;
long long y = (f[0][0]*m[0][1]+f[0][1]*m[1][1])%1000000007;
long long z = (f[1][0]*m[0][0]+f[1][1]*m[1][0])%1000000007;
long long d = (f[1][0]*m[0][1]+f[1][1]*m[1][1])%1000000007;

f[0][0]=x;
f[0][1]=y;
f[1][0]=z;
f[1][1]=d;

}



void power(long long f[2][2], long long n)
{
if(n==0 || n==1)
	return;

long long m[2][2] ={{1,1}, {1,0}};

power(f, n/2);
multiple(f, f);

if(n%2!=0)
	multiple(f,m);

}


long long fibo(long long n)
{

long long f[2][2] = {{1,1},{1,0}};
if(n==0)
	return 0;
power(f, n-1);
return f[0][0];

}




int main()
{
    long long N;
    cin>>N;
    cout<<fibo(N)<<endl;
}
